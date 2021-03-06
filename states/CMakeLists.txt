CMAKE_MINIMUM_REQUIRED (VERSION 3.3)
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/sac2c-variables.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/resolve-sac2c-dependencies.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/build-sac2c-program.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/build-sac2c-module.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake/sac2c-prog-with-versions.cmake")

SET (SAC_MOD_SRC
    IntStack.sac
)

SET (SAC_PROG_SRC
    use_IntStack.sac
)

FOREACH (name ${SAC_PROG_SRC})
    COMPILE_SAC2C_WITH_VER (${name} "${SAC_MOD_SRC}" "${SAC2C_DEF_FLAGS}")
ENDFOREACH (name)

# Make a directory for sac2c output
FILE (MAKE_DIRECTORY "${DLL_BUILD_DIR}/${TARGET_ENV}/${SBI}")

FOREACH (name ${SAC_MOD_SRC})
    SAC2C_COMPILE_MOD (${name} "${SAC_MOD_SRC}" "${SAC2C_DEF_FLAGS}")
ENDFOREACH (name)

