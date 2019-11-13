# Copyright 1994-2018 The MathWorks, Inc.
#
# File    : rsim_unix.tmf   
#
# Abstract:
#	Template makefile for building a UNIX-based "rapid simulation" 
#       executable from the generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is -O.
#	  CPP_OPTS       - C++ compiler options.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see rsim.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = /usr/local/MATLAB/R2019b/bin/glnxa64/gmake
HOST            = UNIX
BUILD           = yes
SYS_TARGET_FILE = rsim.tlc
BUILD_SUCCESS	= *** Created

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = ["Clang v3.1 | gmake (64-bit Mac)", \
             "GNU gcc/g++ | gmake (64-bit Linux)"]

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  TGT_FCN_LIB         - Target function (code replacement) library to use

MODEL                  = rs_bicycle
MODULES                = rt_logging.c rs_bicycle.c rs_bicycle_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rsim_main.c rsim_sup.c rsim_mat.c simulink_solver_api.c rsim_utils.c common_utils.c rt_sim.c
PRODUCT                = $(RELATIVE_PATH_TO_ANCHOR)/rs_bicycle
MAKEFILE               = rs_bicycle.mk
MATLAB_ROOT            = /usr/local/MATLAB/R2019b
ALT_MATLAB_ROOT        = /usr/local/MATLAB/R2019b
START_DIR              = /home/ggarrett/lab/NB10422645/simulation/apps/rs_bicycle/src
S_FUNCTIONS_LIB        = 
COMPUTER               = GLNXA64
BUILDARGS              =  PCMATLABROOT="/usr/local/MATLAB/R2019b" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING
RSIM_PARAMETER_LOADING = 1


SOLVER              = ode3.c
SOLVER_TYPE         = FixedStep
NUMST               = 2
TID01EQ             = 1
NCSTATES            = 4
MULTITASKING        = 0
TGT_FCN_LIB         = ISO_C

RSIM_SOLVER_SELECTION = 1

MODELREFS             = 
OPTIMIZATION_FLAGS    = -DNDEBUG -O -fPIC
ADDITIONAL_LDFLAGS    = 
DEFINES_CUSTOM        = 
TARGET_LANG_EXT       = c
SYSTEM_LIBS           = -L"/usr/local/MATLAB/R2019b/bin/glnxa64" -lmat -lmx -lut -lmwsl_fileio -lmwsl_simtarget_instrumentation -lmwi18n -lmwsigstream -lmwsl_AsyncioQueue -lmwsf_runtime

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

GLOBAL_TIMING_ENGINE       = 0

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Solver ---------------------------------------------
RSIM_WITH_SL_SOLVER = 0

ifeq ($(RSIM_SOLVER_SELECTION),1)
  ifeq ($(SOLVER_TYPE), VariableStep)
    RSIM_WITH_SL_SOLVER = 1
  endif
  ifeq ($(GLOBAL_TIMING_ENGINE),1)
    RSIM_WITH_SL_SOLVER = 1
  endif
endif

ifeq ($(RSIM_SOLVER_SELECTION),2)
  RSIM_WITH_SL_SOLVER = 1
endif

#--------------------------- Tool Specifications -------------------------------

include $(MATLAB_ROOT)/rtw/c/tools/unixtools.mk

#------------------------------Parameter Tuning---------------------------------
ifeq ($(RSIM_PARAMETER_LOADING),1)
  PARAM_CC_OPTS = -DRSIM_PARAMETER_LOADING
endif

#------------------------------ Include Path -----------------------------------
# Additional includes

ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/rs_bicycle_rsim_rtw \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/rapid \
	-I$(MATLAB_ROOT)/rtw/c/rsim \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \


INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES)

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS)  $(PARAM_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(OPTS)  $(PARAM_CC_OPTS)
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DHAVESTDIO -DUNIX

ifeq ($(RSIM_WITH_SL_SOLVER),1)
  CPP_REQ_DEFINES += -DNRT \
                     -DRSIM_WITH_SL_SOLVER
ifeq ($(MULTITASKING),1)			
    CPP_REQ_DEFINES += -DRSIM_WITH_SOLVER_MULTITASKING -DNUMST=$(NUMST) \
	               -DTID01EQ=$(TID01EQ)	 
endif				

else
  CPP_REQ_DEFINES += -DRT -DNUMST=$(NUMST) -DTID01EQ=$(TID01EQ) \
                     -DNCSTATES=$(NCSTATES) -DMT=$(MULTITASKING)
endif

CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)

#----------------------------- Source Files ------------------------------------
USER_SRCS =
SRC_DEP =
REQ_SRCS = $(MODULES)
ifeq ($(MODELREF_TARGET_TYPE), NONE)
    ifneq ($(RSIM_WITH_SL_SOLVER),1)
      REQ_SRCS += $(SOLVER)
    endif
endif

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(REQ_SRCS)

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

#--------------------------- Link flags & libraries ----------------------------

SYSTEM_LIBS += -lm

LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

# On maci, specify rpath
BINDIR = $(MATLAB_ROOT)/bin/$(ARCH)
ifneq (,$(findstring MAC,$(COMPUTER)))
 MAC_LDFLAGS = -Wl,-rpath,$(BINDIR) -Wl,-rpath,@executable_path
 ADDITIONAL_LDFLAGS += $(MAC_LDFLAGS)
endif

#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(LIBS) $(ADDITIONAL_LDFLAGS) $(SYSTEM_LIBS)
	@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"
else
$(PRODUCT) : $(OBJS)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo "### $(MODELLIB) Created"
	@echo "$(BUILD_SUCCESS) $(BUILD_PRODUCT_TYPE): $@"	
endif
ifeq ($(COMPUTER),MAC)
	@echo "### Note : Add $(MATLAB_ROOT)/bin/mac and $(MATLAB_ROOT)/sys/os/mac to the DYLD_LIBRARY_PATH environmental variable to run executable $(MODEL) in separate shell"
endif
	@echo "$(BUILD_SUCCESS) executable: $(MODEL)"

#-------------------------- Standard rules for building modules --------------

%.o : %.c
	$(CC) -c -o $(@F) $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS)$(GCC_WALL_FLAG)  "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -o $(@F) $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

rt_logging.o : /usr/local/MATLAB/R2019b/rtw/c/src/rt_logging.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rt_logging.c

rsim_main.o : /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_main.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_main.c

rsim_sup.o : /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_sup.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_sup.c

rsim_mat.o : /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_mat.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/rsim/rsim_mat.c

simulink_solver_api.o : /usr/local/MATLAB/R2019b/simulink/include/simulink_solver_api.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/simulink/include/simulink_solver_api.c

rsim_utils.o : /usr/local/MATLAB/R2019b/rtw/c/src/rapid/rsim_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rapid/rsim_utils.c

common_utils.o : /usr/local/MATLAB/R2019b/rtw/c/src/rapid/common_utils.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rapid/common_utils.c

rt_sim.o : /usr/local/MATLAB/R2019b/rtw/c/src/rt_sim.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) /usr/local/MATLAB/R2019b/rtw/c/src/rt_sim.c




%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"


# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
