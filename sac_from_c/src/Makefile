#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3 -noWLUR
#SAC2CFLAGS += -noopt

#
# just to make sure that local dependencies can be ressolved properly:
#
export SAC_LIBRARY_PATH := $(SAC_LIBRARY_PATH):../lib

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               = 
# TARGETDIR                   = .
LIBTARGETDIR                = ../lib
INCTARGETDIR                = ../include
# LIBSRCDIR                   = .
# SUBDIRS                     =
# MAKE_NON_LOCAL_DEPENDENCIES = 

#
# Setup for Makefile.versions
#
# EXCLUDE_FILES_FOR_MT        = 
# MAKE_MT_ALSO                = yes
# VERSDIR                     = .

#
# Setup for Makefile.check:
#
CHECKLOGFILE                = ../CHECKLOG
# CHECKDIR                    = .checkdir
# RT_FLAGS                    =
# INPSDIR                     = 
#
#######################################################################################

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg

MODTARGETS    := $(patsubst $(LIBTARGETDIR)/%.lib,$(LIBTARGETDIR)/lib%.a, $(MODTARGETS))

