#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3
#SAC2CFLAGS += -mt
#SAC2CFLAGS += -noopt

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               =
# TARGETDIR                   = .
# LIBTARGETDIR                = .
LIBSRCDIR                   = $(patsubst %.libDD,src/%/,$@)
SUBDIRS                     = src/List
MAKE_NON_LOCAL_DEPENDENCIES = yes
 
#
# Setup for Makefile.check:
#
# CHECKDIR = .checkdir
# RT_FLAGS =
#
#######################################################################################

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg

