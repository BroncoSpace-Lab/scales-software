// ======================================================================
// \title  PyBinAc.hpp
// \brief  autocode python binding header
// ======================================================================
#include <fprime-python/FprimePy/FprimePy.hpp>



#include <build-fprime-automatic-native/Components/MLComponent/MLComponentComponentAc.hpp>



#include <build-fprime-automatic-native/Components/PythonComponent/PythonComponentComponentAc.hpp>





#include <Fw/Cmd/CmdString.hpp>



#include <Fw/Log/LogString.hpp>






namespace Components {
    class __attribute__((visibility("default"))) MLComponent : public MLComponentComponentBase {
      public:
        /**
         * MLComponent: c++ function implementations that delegate across to the python side.
         */
        MLComponent(const char* name);

        // init function loads python code
        void init(const NATIVE_INT_TYPE queueDepth,const NATIVE_INT_TYPE instance);

        ~MLComponent();

        
        void SET_ML_PATH_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdStringArg& path);
        void SET_INFERENCE_PATH_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdStringArg& path);
        void MULTI_INFERENCE_cmdHandler(FwOpcodeType opCode, U32 cmdSeq);
        void CLEAR_INFERENCE_PATH_cmdHandler(FwOpcodeType opCode, U32 cmdSeq);
        

        
      public:
        
        // Changing access modifiers for command response
        
        // using MLComponentComponentBase::cmdResponse_out;
        void cmdResponse_out(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdResponse::T response)
        {
          Fw::CmdResponse convertResponse(response);
          MLComponentComponentBase::cmdResponse_out(opCode, cmdSeq, convertResponse);
        }
        
        using MLComponentComponentBase::getTime;// Changing access modifiers for output ports
        
        // Changing access modifiers for output calls to channels
        
        // Changing access modifiers for output calls to events
        // using MLComponentComponentBase::log_ACTIVITY_HI_MLSet;
        void log_ACTIVITY_HI_MLSet(const Fw::LogStringArg greeting)
        {
          Fw::LogStringArg message(greeting);
          MLComponentComponentBase::log_ACTIVITY_HI_MLSet(message);
        } 
        // using MLComponentComponentBase::log_ACTIVITY_HI_InferenceSet;
        void log_ACTIVITY_HI_InferenceSet(const Fw::LogStringArg greeting)
        {
          Fw::LogStringArg message(greeting);
          MLComponentComponentBase::log_ACTIVITY_HI_InferenceSet(message);
        } 
        // using MLComponentComponentBase::log_ACTIVITY_HI_InferenceOutput;
        void log_ACTIVITY_HI_InferenceOutput(const Fw::LogStringArg greeting, const Fw::LogStringArg secondGreeting)
        {
          Fw::LogStringArg message(greeting);
          Fw::LogStringArg messageTwo(secondGreeting);
          MLComponentComponentBase::log_ACTIVITY_HI_InferenceOutput(message, messageTwo);
        } 
        
        // Changing access modifiers for parameter calls
        

      public:
        py::object m_self;
    };
}; // Namespace Components


namespace Components {
    class __attribute__((visibility("default"))) PythonComponent : public PythonComponentComponentBase {
      public:
        /**
         * PythonComponent: c++ function implementations that delegate across to the python side.
         */
        PythonComponent(const char* name);

        // init function loads python code
        void init(const NATIVE_INT_TYPE queueDepth,const NATIVE_INT_TYPE instance);

        ~PythonComponent();

        
        void SAY_HELLO_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdStringArg& greeting);
        

        
      public:
        
        // Changing access modifiers for command response
        
        // using PythonComponentComponentBase::cmdResponse_out;
        void cmdResponse_out(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdResponse::T response)
        {
          Fw::CmdResponse convertResponse(response);
          PythonComponentComponentBase::cmdResponse_out(opCode, cmdSeq, convertResponse);
        }
        
        using PythonComponentComponentBase::getTime;// Changing access modifiers for output ports
        
        // Changing access modifiers for output calls to channels
        using PythonComponentComponentBase::tlmWrite_GreetingCount;
        
        // Changing access modifiers for output calls to events
        // using PythonComponentComponentBase::log_ACTIVITY_HI_Hello;
        void log_ACTIVITY_HI_Hello(const Fw::LogStringArg greeting)
        {
          Fw::LogStringArg message(greeting);
          PythonComponentComponentBase::log_ACTIVITY_HI_Hello(message);
        } 
        
        // Changing access modifiers for parameter calls
        

      public:
        py::object m_self;
    };
}; // Namespace Components






