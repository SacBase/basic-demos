#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -maxlur 3
#SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3
#SAC2CFLAGS += -noopt -doPHM -doAPS -doRCAO -doMSCA

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               = 
# TARGETDIR                   = .
# LIBTARGETDIR                = .
# INCTARGETDIR                = .
# LIBSRCDIR                   = .
# SUBDIRS                     = sac_from_c
SUBDIRS                     = simple states composing_programs c_from_sac 

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

include $(SACBASE)/Makefiles/Makefile_template.prg

