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
LIBTARGETDIR                = lib
INCTARGETDIR                = include
LIBSRCDIR                   = src
SUBDIRS                     = src
# MAKE_NON_LOCAL_DEPENDENCIES =
 
#
# Setup for Makefile.check:
#
# CHECKDIR = .checkdir
# RT_FLAGS =
#
#######################################################################################



CC      = gcc
CCFLAGS = -ansi -g -Wall $(LIBS) $(INCS)
LIBS    = -L$(SACBASE)/runtime -L$(LIBTARGETDIR)
INCS    = -I$(SACBASE)/runtime -I$(INCTARGETDIR)

TARGETS    = tutorial relax overload usePhm features useTwoLibs objects
DEPTARGETS = $(patsubst %,%.d,$(TARGETS))

all: $(DEPTARGETS)


include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg


################################################################################
#
# tutorial:
#
tutorial.d: tutorialMod.aDD tutorial

tutorial: tutorial.c include/tutorialMod.h
	$(CC) $(CCFLAGS) -o tutorial tutorial.c -ltutorialMod -lsac_heapmgr -lsac


################################################################################
#
# relax:
#
relax.d: relaxMod.aDD relax

relax: relax.c include/relaxMod.h
	$(CC) $(CCFLAGS) -o relax relax.c -lrelaxMod -lsac_heapmgr -lsac


################################################################################
#
# overload:
#
overload.d: overloadMod.aDD overload

overload: overload.c include/overloadMod.h
	$(CC) $(CCFLAGS) -o overload overload.c -loverloadMod  -lsac_heapmgr -lsac


################################################################################
#
# usePhm:
#
usePhm.d:
	$(MAKE) "SAC2CFLAGS= $(SAC2CFLAGS) -check h" usePhmMod.aDD
	$(MAKE) usePhm

usePhm: usePhm.c include/usePhmMod.h
	$(CC) $(CCFLAGS) -o usePhm usePhm.c -lusePhmMod -lsac_heapmgr_diag -lsac


################################################################################
#
# features:
#
features.d:
	$(MAKE) "SAC2CFLAGS= $(SAC2CFLAGS) -check h" featuresMod_fix.aDD
	$(MAKE) "SAC2CFLAGS= $(SAC2CFLAGS) -check h" featuresMod_gen.aDD
	$(MAKE) features

features: features.c include/featuresMod_fix.h include/featuresMod_gen.h
	$(CC) $(CCFLAGS) -o features features.c \
	                 -lfeaturesMod_fix -lfeaturesMod_gen \
	                 $(SACBASE)/stdlib/hidden/lib/StringC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibreScan.a \
	                 $(SACBASE)/stdlib/world/system/lib/Terminal.a \
	                 $(SACBASE)/stdlib/world/system/lib/SysErr.a \
	                 $(SACBASE)/stdlib/world/system/lib/FileSystem.a \
	                 $(SACBASE)/stdlib/world/system/lib/World.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/TermFile.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/File.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/List.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/Char.a \
	                 $(SACBASE)/stdlib/hidden/lib/MathC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibrePrint.a \
	                 $(SACBASE)/stdlib/hidden/lib/PrintArray.a \
	                 -lm -lsac_heapmgr_diag -lsac


################################################################################
#
# useTwoLibs:
#
useTwoLibs.d: useTwoLibsMod1.aDD useTwoLibsMod2.aDD useTwoLibs

useTwoLibs: useTwoLibs.c include/useTwoLibsMod1.h include/useTwoLibsMod2.h
	$(CC) $(CCFLAGS) -o useTwoLibs useTwoLibs.c \
	                 -luseTwoLibsMod1 -luseTwoLibsMod2 \
	                 $(SACBASE)/stdlib/hidden/lib/StringC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibreScan.a \
	                 $(SACBASE)/stdlib/world/system/lib/Terminal.a \
	                 $(SACBASE)/stdlib/world/system/lib/SysErr.a \
	                 $(SACBASE)/stdlib/world/system/lib/FileSystem.a \
	                 $(SACBASE)/stdlib/world/system/lib/World.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/TermFile.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/File.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/List.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/Char.a \
	                 $(SACBASE)/stdlib/hidden/lib/MathC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibrePrint.a \
	                 $(SACBASE)/stdlib/hidden/lib/PrintArray.a \
	                 -lm -lsac_heapmgr -lsac

################################################################################
#
# objects:
#

objects.d:
	$(MAKE) "SAC2CFLAGS= $(SAC2CFLAGS) -noPHM" IntStack.aDD
	$(MAKE) "SAC2CFLAGS= $(SAC2CFLAGS) -noPHM" objectsMod.aDD
	$(MAKE) objects

objects: objects.c
	$(CC) $(CCFLAGS) -o objects objects.c -lIntStack -lobjectsMod \
	                 $(SACBASE)/stdlib/hidden/lib/StringC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibreScan.a \
	                 $(SACBASE)/stdlib/world/system/lib/Terminal.a \
	                 $(SACBASE)/stdlib/world/system/lib/SysErr.a \
	                 $(SACBASE)/stdlib/world/system/lib/FileSystem.a \
	                 $(SACBASE)/stdlib/world/system/lib/World.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/TermFile.a \
	                 $(SACBASE)/stdlib/world/stdio/lib/File.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/List.a \
	                 $(SACBASE)/stdlib/modules/structures/lib/Char.a \
	                 $(SACBASE)/stdlib/hidden/lib/MathC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibrePrint.a \
	                 $(SACBASE)/stdlib/hidden/lib/PrintArray.a \
	                 -lm -lsac



################################################################################
#
# additions to some phony targets imported from Makefile.standard:
#

clean: local_clean

local_clean:
	$(RM) $(TARGETS)
