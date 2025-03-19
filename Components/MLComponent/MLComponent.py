""" MLComponent.py:

Python implementation of the MLComponent fprime component. This component is dependent on autocoded bindings that
map to this component. **Note:** ensure this file is renamed to MLComponent.py in the current folder.
"""

# Required imports for the implementation to work
import fprime_pybind

# Typical, but optional, imports
import Fw
import Components


import importlib
import os
import resnet_cifar100



class MLComponent(fprime_pybind.MLComponentBase):
    """ Implementation of MLComponent component. """

    def __init__(self):
        """ Constructor implementation """
        self.model = None
        self.path = None
        pass # TODO: fill out custom constructing logic

    def SET_ML_PATH_cmdHandler(self, opCode, cmdSeq, path):
        """ Command handler for SET_ML_PATH """
        try:
            self.model = importlib.import_module(path)
        except:
            self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_VALIDATION_ERROR)
            return
        
        self.log_ACTIVITY_HI_MLSet(Fw.LogStringArg(path))
        self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_OK) # TODO: implement SET_ML_PATH

    def SET_INFERENCE_PATH_cmdHandler(self, opCode, cmdSeq, path):
        """ Command handler for SET_INFERENCE_PATH """
        if not os.path.isdir(path):
            self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_VALIDATION_ERROR)
            return
        
        self.path = path
        self.log_ACTIVITY_HI_InferenceSet(Fw.LogStringArg(path))
        self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_OK) # TODO: implement SET_INFERENCE_PATH

    def INFERENCE_ONCE_cmdHandler(self, opCode, cmdSeq):
        """ Command handler for INFERENCE_ONCE """
        
        try:
            self.model.main()
        except:
            self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_EXECUTION_ERROR)
        
        # if self.outputs:
        #     for item in self.outputs:
        #         output = Fw.LogStringArg(item)
        #         self.log_ACTIVITY_HI_InferenceOutput(output)
                
        self.cmdResponse_out(opCode, cmdSeq, Fw.CmdResponse.COMMAND_OK) # TODO: implement INFERENCE_ONCE

    
    