#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -ssa -maxlur 3
#SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3
#SAC2CFLAGS += -noopt -doPHM -doAPS -doRCAO -doMSCA

#
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               =
# TARGETDIR                   = .
LIBTARGETDIR                = lib
INCTARGETDIR                = include
LIBSRCDIR                   = src
SUBDIRS                     = src inputs
# MAKE_NON_LOCAL_DEPENDENCIES = 

#
# Setup for Makefile.versions
#
# EXCLUDE_FILES_FOR_MT        = 
MAKE_MT_ALSO                = yes
# VERSDIR                     = .

#
# Setup for Makefile.check:
#
CHECKLOGFILE                = ./CHECKLOG
# CHECKDIR                    = .checkdir
# RT_FLAGS                    =
INPSDIR                     = inputs
#
#######################################################################################



TARGETS    = tutorial relax overload usePhm features useTwoLibs objects useTypes
DEPTARGETS = $(patsubst %,%.d,$(TARGETS))

all: $(DEPTARGETS)

RES_FILES  = $(patsubst %,$(CHECKDIR)/%.res,$(TARGETS))

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg

LIBS       = -L$(SACBASE)/runtime -L$(LIBTARGETDIR)
INCS       = -I$(SACBASE)/runtime -I$(INCTARGETDIR)
CCFLAGS   += $(LIBS) $(INCS)



################################################################################
#
# tutorial:
#

tutorial.d: tutorialMod.aDD tutorial

tutorial: tutorial.c include/tutorialMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o tutorial tutorial.c -ltutorialMod $(LIB_PHM) -lsac


################################################################################
#
# relax:
#

relax.d: relaxMod.aDD relax

relax: relax.c include/relaxMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o relax relax.c -lrelaxMod $(LIB_PHM) -lsac


################################################################################
#
# overload:
#

overload.d: overloadMod.aDD overload

overload: overload.c include/overloadMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o overload overload.c -loverloadMod  $(LIB_PHM) -lsac


################################################################################
#
# usePhm:
#

usePhm.d:
	$(MAKE) usePhmMod.aDD
	$(MAKE) usePhm

usePhm: usePhm.c include/usePhmMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o usePhm usePhm.c -lusePhmMod $(LIB_PHM) -lsac


################################################################################
#
# features:
#

features.d:
	$(MAKE) featuresMod_fix.aDD
	$(MAKE) featuresMod_gen.aDD
	$(MAKE) features

features: features.c include/featuresMod_fix.h include/featuresMod_gen.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o features features.c \
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
	                 $(SACBASE)/stdlib/modules/structures/lib/Constants.a \
	                 $(SACBASE)/stdlib/hidden/lib/MathC.a \
	                 $(SACBASE)/stdlib/hidden/lib/FibrePrint.a \
	                 $(SACBASE)/stdlib/hidden/lib/PrintArray.a \
	                 $(LIB_M) $(LIB_PHM) -lsac


################################################################################
#
# useTwoLibs:
#

useTwoLibs.d: useTwoLibsMod1.aDD useTwoLibsMod2.aDD useTwoLibs

useTwoLibs: useTwoLibs.c include/useTwoLibsMod1.h include/useTwoLibsMod2.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o useTwoLibs useTwoLibs.c \
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
	                 $(LIB_M) $(LIB_PHM) -lsac


################################################################################
#
# objects:
#

objects.d:
	$(MAKE) IntStack.aDD
	$(MAKE) objectsMod.aDD
	$(MAKE) objects

objects: objects.c include/IntStack.h include/objectsMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o objects objects.c -lIntStack -lobjectsMod \
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
	                 $(LIB_M) $(LIB_PHM) -lsac


################################################################################
#
# useTypes:
#

useTypes.d: useTypesMod.aDD useTypes

useTypes: useTypes.c include/useTypesMod.h
	$(CC) $(CCFLAGS) $(LDFLAGS) -o useTypes useTypes.c \
			-luseTypesMod \
			$(SACBASE)/stdlib/world/system/lib/SysErr.a \
			$(SACBASE)/stdlib/hidden/lib/StringC.a \
			$(SACBASE)/stdlib/world/system/lib/World.a \
			$(SACBASE)/stdlib/world/system/lib/FileSystem.a \
			$(SACBASE)/stdlib/world/system/lib/Terminal.a \
			$(SACBASE)/stdlib/world/stdio/lib/TermFile.a \
			$(SACBASE)/stdlib/world/stdio/lib/File.a \
			$(SACBASE)/stdlib/classes/random/lib/Random.a \
			$(SACBASE)/stdlib/modules/structures/lib/List.a \
			$(SACBASE)/stdlib/hidden/lib/MathC.a \
			$(SACBASE)/stdlib/modules/structures/lib/Char.a \
			$(LIB_M) $(LIB_PHM) -lsac



################################################################################
#
# additions to some phony targets imported from Makefile.standard:
#

clean: local_clean

local_clean:
	$(RM) $(TARGETS)


