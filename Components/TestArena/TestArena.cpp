// ======================================================================
// \title  TestArena.cpp
// \author lex
// \brief  cpp file for TestArena component implementation class
// ======================================================================

#include "Components/TestArena/TestArena.hpp"
#include "FpConfig.hpp"
#include "ArenaApi.h"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TestArena ::
    TestArena(const char* const compName) :
      TestArenaComponentBase(compName)
  {

  }

  TestArena ::
    ~TestArena()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void TestArena ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    Arena::ISystem* pSystem = Arena::OpenSystem();
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
