// ======================================================================
// \title  RunLucidCamera.cpp
// \author scalesagx
// \brief  cpp file for RunLucidCamera component implementation class
// ======================================================================

#include "Components/RunLucidCamera/RunLucidCamera.hpp"
#include "FpConfig.hpp"
#include "ArenaApi.h"
#include <stdio.h>
#include "SaveApi.h"

#define TAB1 "  "

// =-=-=-=-=-=-=-=-=-
// =-=- SETTINGS =-=-
// =-=-=-=-=-=-=-=-=-

// pixel format
#define PIXEL_FORMAT BGR8

// file name
#define FILE_NAME "Components/RunLucidCamera/Images/image.png" //make parameter later
//also change to make a new image each time and not just replace the previous one

void SaveImage(Arena::IImage* pImage, const char* filename)
  {
    // convert image
    std::cout << TAB1 << "Convert image to " << GetPixelFormatName(PIXEL_FORMAT) << "\n";

    auto pConverted = Arena::ImageFactory::Convert(
      pImage,
      PIXEL_FORMAT);

    // prepare image parameters
    std::cout << TAB1 << "Prepare image parameters\n";

    Save::ImageParams params(
      pConverted->GetWidth(),
      pConverted->GetHeight(),
      pConverted->GetBitsPerPixel());

    // prepare image writer
    std::cout << TAB1 << "Prepare image writer\n";

    Save::ImageWriter writer(
      params,
      filename);

    // Set image writer to PNG
    //   Set the output file format of the image writer to PNG.
    //   The writer saves the image file as PNG file even without
    //	 the extension in the file name. Aside from this setting, 
    //   compression level can be set between 0 to 9 and the image
    //   can be created using interlacing by changing the parameters. 

    std::cout << TAB1 << "Set image writer to PNG\n";

    writer.SetPng(".png", 0, false);

    // save image
    std::cout << TAB1 << "Save image\n";

    writer << pConverted->GetData();

    // destroy converted image
    Arena::ImageFactory::Destroy(pConverted);
  }

  Arena::DeviceInfo SelectDevice(std::vector<Arena::DeviceInfo>& deviceInfos)
  {
    if (deviceInfos.size() == 1)
    {
      std::cout << "\n"
            << TAB1 << "Only one device detected: " << deviceInfos[0].ModelName() << TAB1 << deviceInfos[0].SerialNumber() << TAB1 << deviceInfos[0].IpAddressStr() << ".\n";
      std::cout << TAB1 << "Automatically selecting this device.\n";
      return deviceInfos[0];
    }

    std::cout << "\nSelect device:\n";
    for (size_t i = 0; i < deviceInfos.size(); i++)
    {
      std::cout << TAB1 << i + 1 << ". " << deviceInfos[i].ModelName() << TAB1 << deviceInfos[i].SerialNumber() << TAB1 << deviceInfos[i].IpAddressStr() << "\n";
    }
    size_t selection = 0;

    // do
    // {
    //   // std::cout << TAB1 << "Make selection (1-" << deviceInfos.size() << "): ";
    //   // std::cin >> selection;

    //   // if (std::cin.fail())
    //   // {
    //   //   std::cin.clear();
    //   //   while (std::cin.get() != '\n')
    //   //     ;
    //   //   std::cout << TAB1 << "Invalid input. Please enter a number.\n";
    //   // }
    //   // else if (selection <= 0 || selection > deviceInfos.size())
    //   // {
    //   //   std::cout << TAB1 << "Invalid device selected. Please select a device in the range (1-" << deviceInfos.size() << ").\n";
    //   // }

    // } while (selection <= 0 || selection > deviceInfos.size());

    return deviceInfos[0];
  }

Arena::ISystem* pSystem;
Arena::IDevice* pDevice;

// namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Components::RunLucidCamera ::
    RunLucidCamera(const char* const compName) :
      RunLucidCameraComponentBase(compName)
  {
    
  }

  Components::RunLucidCamera ::
    ~RunLucidCamera()
  {
    pSystem->DestroyDevice(pDevice);
    Arena::CloseSystem(pSystem);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Components::RunLucidCamera ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    // flag to track when an exception has been thrown
    bool exceptionThrown = false;

    std::cout << "Cpp_Save_Png";
    // this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    try
    {
      

      pDevice->StartStream();
      Arena::IImage* pImage = pDevice->GetImage(2000);

      std::cout << "Commence example\n\n";
      SaveImage(pImage, FILE_NAME);
      std::cout << "\nExample complete\n";

      // clean up example
      pDevice->RequeueBuffer(pImage);
      pDevice->StopStream();
      
    }
    catch (GenICam::GenericException& ge)
    {
      std::cout << "\nGenICam exception thrown: " << ge.what() << "\n";
      exceptionThrown = true;
    }
    catch (std::exception& ex)
    {
      std::cout << "\nStandard exception thrown: " << ex.what() << "\n";
      exceptionThrown = true;
    }
    catch (...)
    {
      std::cout << "\nUnexpected exception thrown\n";
      exceptionThrown = true;
    }

    // std::cout << "Press enter to complete\n";
    // std::cin.ignore();
    // std::getchar();

    if (exceptionThrown) {
      this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::EXECUTION_ERROR);
      return;
    } 
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    return;



  }

  void Components::RunLucidCamera ::
    SETUP_CAMERA_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    // prepare example
    pSystem = Arena::OpenSystem();
    pSystem->UpdateDevices(100);
    std::vector<Arena::DeviceInfo> devices = pSystem->GetDevices();
    //works here
    this->log_ACTIVITY_HI_DebugLogEvent(Fw::LogStringArg("Working"));
    if (devices.size() == 0)
    {
      std::cout << "\nNo camera connected\nPress enter to complete\n";
      // std::getchar();
      // return 0;
      this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::EXECUTION_ERROR);
      return;
    }
    Arena::DeviceInfo selectedDevice = SelectDevice(devices);
    // this->log_ACTIVITY_HI_DebugLogEvent(Fw::LogStringArg("Working 1"));
    pDevice = pSystem->CreateDevice(selectedDevice);
    this->log_ACTIVITY_HI_DebugLogEvent(Fw::LogStringArg("Working 2"));
    // enable stream auto negotiate packet size
    Arena::SetNodeValue<bool>(pDevice->GetTLStreamNodeMap(), "StreamAutoNegotiatePacketSize", true);

    // enable stream packet resend
    Arena::SetNodeValue<bool>(pDevice->GetTLStreamNodeMap(), "StreamPacketResendEnable", true);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

// }
