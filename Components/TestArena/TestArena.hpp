// ======================================================================
// \title  TestArena.hpp
// \author lex
// \brief  hpp file for TestArena component implementation class
// ======================================================================

#ifndef Components_TestArena_HPP
#define Components_TestArena_HPP

#include "Components/TestArena/TestArenaComponentAc.hpp"

namespace Components {

  class TestArena :
    public TestArenaComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TestArena object
      TestArena(
          const char* const compName //!< The component name
      );

      //! Destroy TestArena object
      ~TestArena();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
