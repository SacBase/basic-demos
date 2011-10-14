#######################################################################################
#
# For installing the demos, it has to made sure these have been unpacked completely.
# Therefore, we have to wrap up the standard make mechanism as included by
# the target "standard_all" from Makefile_template.prg by potentially calling
# "make untar" first:
#

all: simple/gcd.sac
	$(MAKE) standard_all

simple/gcd.sac:
	$(MAKE) untar TARFILENAME=demo.tar

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
SUBDIRS                     = simple states tutorials numerical livermore_loops \
                              c_from_sac cryptography fun
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
CHECKLOGFILE                = ./CHECKLOG
# CHECKDIR                    = .checkdir
# RT_FLAGS                    =
# INPSDIR                     = 
#
#######################################################################################

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg

