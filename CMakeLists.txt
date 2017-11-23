CMAKE_MINIMUM_REQUIRED (VERSION 3.3)

PROJECT (sac-basic-demos)

# Where the compiled sac modules result
SET (DLL_BUILD_DIR  "${PROJECT_BINARY_DIR}/lib")

# For what targets we build modules
SET (TARGETS            seq mt_pth  CACHE STRING "Build stdlib-jpeg for these targets")
SET (SAC2C_EXEC                     CACHE STRING "A path to sac2c compiler")
SET (LINKSETSIZE        "0"         CACHE STRING "Set a value for -linksetsize parameter of sac2c")

# Check whether sac2c is operational
INCLUDE ("cmake-common/check-sac2c.cmake")
INCLUDE ("cmake-common/misc-macros.cmake")

SET (SAC2C_DEF_FLAGS -v0 -linksetsize ${LINKSETSIZE} -L ${DLL_BUILD_DIR} -T ${DLL_BUILD_DIR})

# For every target run CMakeLists.txt in src
FOREACH (TARGET IN ITEMS ${TARGETS})
    ADD_SUBDIRECTORY (simple   simple-${TARGET})
    ADD_SUBDIRECTORY (states   states-${TARGET})
    ADD_SUBDIRECTORY (sac_from_c   sac_from_c-${TARGET})
    ADD_SUBDIRECTORY (c_from_sac   c_from_sac-${TARGET})
    ADD_SUBDIRECTORY (composing_programs   composing_programs-${TARGET})
ENDFOREACH ()
