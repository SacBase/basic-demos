CMAKE_MINIMUM_REQUIRED (VERSION 3.3)
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/sac2c-variables.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/resolve-sac2c-dependencies.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/build-sac2c-program.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/build-sac2c-module.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake/sac2c-prog-with-versions.cmake")

SET (SAC_MOD_SRC
    MyList.sac
)

SET (SAC_PROG_SRC
    quicksort_list.sac
)

SET (C_DEPS_SRC
    src/MyList/tl.c
    src/MyList/take.c
    src/MyList/nth.c
    src/MyList/nil.c
    src/MyList/length.c
    src/MyList/hd.c
    src/MyList/free.c
    src/MyList/empty.c
    src/MyList/drop.c
    src/MyList/cons.c
    src/MyList/append.c)


SET (SAC2C_DEF_FLAGS ${SAC2C_DEF_FLAGS} -DFIXED_SEED)

FOREACH(name ${C_DEPS_SRC})
  SET (src "${CMAKE_CURRENT_SOURCE_DIR}/${name}")

  GET_FILENAME_COMPONENT (dir ${name} DIRECTORY)

  GET_FILENAME_COMPONENT (dst ${name} NAME_WE)
  SET (dst "${CMAKE_CURRENT_BINARY_DIR}/${dir}/${dst}${OBJEXT}")

  # Make sure that we put the object file in the same location where
  # the source file was.
  FILE (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${dir}")

  ADD_CUSTOM_COMMAND (
    OUTPUT "${dst}"
    MAIN_DEPENDENCY "${src}"
    IMPLICIT_DEPENDS C "${src}"
    COMMAND
        ${SAC2C} -Xc -I${CMAKE_CURRENT_SOURCE_DIR}/${dir}
                 -Xc -I${CMAKE_CURRENT_BINARY_DIR}/${dir}
                 -v0 -noprelude -cc ccmod -o "${dst}" "${src}"
    WORKING_DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/${dir}"
    COMMENT "Generating ${dst} for target `${TARGET}'"
  )
ENDFOREACH(name)

FOREACH (name ${SAC_PROG_SRC})
    COMPILE_SAC2C_WITH_VER (${name} "${SAC_MOD_SRC}" "${SAC2C_DEF_FLAGS}")
ENDFOREACH (name)

# Make a directory for sac2c output
FILE (MAKE_DIRECTORY "${DLL_BUILD_DIR}/${TARGET_ENV}/${SBI}")

FOREACH (name ${SAC_MOD_SRC})
    SAC2C_COMPILE_MOD (${name} "${SAC_MOD_SRC}" "${SAC2C_DEF_FLAGS}")
ENDFOREACH (name)

