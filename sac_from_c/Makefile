#
# $Log$
# Revision 1.3  2000/11/17 13:54:56  nmw
# *** empty log message ***
#
# Revision 1.2  2000/11/17 13:13:06  nmw
# cvs header added
#
#

#######################################################################################
#
# General Setup:
#
SAC2CFLAGS = -O3 -v1 -noLIR -maxlur 3
#SAC2CFLAGS += -mt
#SAC2CFLAGS += -noopt

#lls
# Setup for Makefile.standard:
#
# EXCLUDE_FILES               =
# TARGETDIR                   = .
LIBTARGETDIR                = lib
LIBSRCDIR                   = src
# SUBDIRS                     =
# MAKE_NON_LOCAL_DEPENDENCIES =
 
#
# Setup for Makefile.check:
#
# CHECKDIR = .checkdir
# RT_FLAGS =
#
#######################################################################################


HEADERTARGETDIR = include

GCC_CLIB_FLAGS = -ansi -g -Wall
GCC_CLIB_DIRS  = -L$(SACBASE)/runtime -L$(LIBTARGETDIR) -I$(SACBASE)/runtime -I$(HEADERTARGETDIR) 



all: tutorial relax overload usePhm features useTwoLibs objects

include $(SACBASE)/stdlib/Makefiles/Makefile_template.prg

tutorial: tutorial.c tutorialMod.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o tutorial tutorial.c -ltutorialMod -lsac_heapmgr -lsac

relax: relax.c relaxMod.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o relax relax.c -lrelaxMod -lsac_heapmgr -lsac

overload: overload.c overloadMod.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o overload overload.c -loverloadMod  -lsac_heapmgr -lsac

#phm debug output is missing
usePhm: usePhm.c usePhmMod.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o usePhm usePhm.c -lusePhmMod -lsac_heapmgr_diag -lsac

#phm debug output is missing
features: features.c featuresMod_fix.libDD featuresMod_gen.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o features features.c -lfeaturesMod_fix -lfeaturesMod_gen $(SACBASE)/stdlib/hidden/lib/StringC.a $(SACBASE)/stdlib/hidden/lib/FibreScan.a $(SACBASE)/stdlib/world/system/lib/Terminal.a $(SACBASE)/stdlib/world/system/lib/SysErr.a $(SACBASE)/stdlib/world/system/lib/FileSystem.a $(SACBASE)/stdlib/world/system/lib/World.a $(SACBASE)/stdlib/world/stdio/lib/TermFile.a $(SACBASE)/stdlib/world/stdio/lib/File.a $(SACBASE)/stdlib/modules/structures/lib/List.a $(SACBASE)/stdlib/modules/structures/lib/Char.a $(SACBASE)/stdlib/hidden/lib/MathC.a $(SACBASE)/stdlib/hidden/lib/FibrePrint.a $(SACBASE)/stdlib/hidden/lib/PrintArray.a -lm -lsac_heapmgr_diag -lsac

useTwoLibs: useTwoLibs.c useTwoLibsMod1.libDD useTwoLibsMod2.libDD
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o useTwoLibs useTwoLibs.c -luseTwoLibsMod1 -luseTwoLibsMod2 $(SACBASE)/stdlib/hidden/lib/StringC.a $(SACBASE)/stdlib/hidden/lib/FibreScan.a $(SACBASE)/stdlib/world/system/lib/Terminal.a $(SACBASE)/stdlib/world/system/lib/SysErr.a $(SACBASE)/stdlib/world/system/lib/FileSystem.a $(SACBASE)/stdlib/world/system/lib/World.a $(SACBASE)/stdlib/world/stdio/lib/TermFile.a $(SACBASE)/stdlib/world/stdio/lib/File.a $(SACBASE)/stdlib/modules/structures/lib/List.a $(SACBASE)/stdlib/modules/structures/lib/Char.a $(SACBASE)/stdlib/hidden/lib/MathC.a $(SACBASE)/stdlib/hidden/lib/FibrePrint.a $(SACBASE)/stdlib/hidden/lib/PrintArray.a -lm -lsac_heapmgr -lsac

objects: objects.c libIntStack.a libobjectsMod.a IntStack.lib
	if (test -r lib/*.h) ; then mv lib/*.h include/ ; fi
	gcc $(GCC_CLIB_FLAGS) $(GCC_CLIB_DIRS) -o objects objects.c -lIntStack -lobjectsMod $(SACBASE)/stdlib/hidden/lib/StringC.a $(SACBASE)/stdlib/hidden/lib/FibreScan.a $(SACBASE)/stdlib/world/system/lib/Terminal.a $(SACBASE)/stdlib/world/system/lib/SysErr.a $(SACBASE)/stdlib/world/system/lib/FileSystem.a $(SACBASE)/stdlib/world/system/lib/World.a $(SACBASE)/stdlib/world/stdio/lib/TermFile.a $(SACBASE)/stdlib/world/stdio/lib/File.a $(SACBASE)/stdlib/modules/structures/lib/List.a $(SACBASE)/stdlib/modules/structures/lib/Char.a $(SACBASE)/stdlib/hidden/lib/MathC.a $(SACBASE)/stdlib/hidden/lib/FibrePrint.a $(SACBASE)/stdlib/hidden/lib/PrintArray.a -lm -lsac

libIntStack.a: src/IntStack.sac
	sac2c -v1 -noLIR -genlib c -noPHM -o$(LIBTARGETDIR) src/IntStack.sac

IntStack.lib: src/IntStack.sac
	sac2c -v1 -noLIR -genlib sac -noPHM -o$(LIBTARGETDIR) src/IntStack.sac

libobjectsMod.a:src/objectsMod.sac IntStack.lib
	sac2c -v1 -noLIR -genlib c -noPHM -L$(LIBTARGETDIR) -o$(LIBTARGETDIR) src/objectsMod.sac

clean: local_clean

local_clean:
	rm -rf lib/*.a lib/*.lib include/*.h *.dec src/.*.d tutorial relax overload usePhm features useTwoLibs objects
