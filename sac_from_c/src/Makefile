#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3
#SAC2CFLAGS += -mt
#SAC2CFLAGS += -noopt

#
# just to make sure that local dependencies can be ressolved properly:
#
SAC_LIBRARY_PATH := $(SAC_LIBRARY_PATH)\:../lib

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               =
# TARGETDIR                   = .
LIBTARGETDIR                = ../lib
INCTARGETDIR                = ../include
# LIBSRCDIR                   = .
# SUBDIRS                     =
# MAKE_NON_LOCAL_DEPENDENCIES = yes
 
#
# Setup for Makefile.check:
#
# CHECKDIR = .checkdir
# RT_FLAGS =
#
#######################################################################################

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg


