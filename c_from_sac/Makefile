#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -maxlur 3 -DFIXED_SEED
#SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3 -DFIXED_SEED
#SAC2CFLAGS += -noopt -doPHM -doAPS -doRCAO -doMSCA

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               = 
# TARGETDIR                   = .
# LIBTARGETDIR                = .
# INCTARGETDIR                = .
# LIBSRCDIR                   = $(patsubst %.libDD,src/%/,$@)
SUBDIRS                     = src/List
#MAKE_NON_LOCAL_DEPENDENCIES = yes

#
# Setup for Makefile.versions
#
# EXCLUDE_FILES_FOR_MT        = 
# MAKE_MT_ALSO                = yes
# VERSDIR                     = .

#
# Setup for Makefile.check:
#
CHECKLOGFILE                = ./CHECKLOG
# CHECKDIR                    = .checkdir
# RT_FLAGS                    =
# INPSDIR                     = 
#
#######################################################################################

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg
