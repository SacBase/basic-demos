CMAKE_MINIMUM_REQUIRED (VERSION 3.3)
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/sac2c-variables.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/check-sac4c.cmake")
INCLUDE ("${CMAKE_SOURCE_DIR}/cmake-common/resolve-sac2c-dependencies.cmake")

SET (SAC_MOD_SRC
    Sum.sac
)

# Make a directory for sac2c output
FILE (MAKE_DIRECTORY "${DLL_BUILD_DIR}/${TARGET_ENV}/${SBI}")

# Default sac4c compiler flags.
SET (SAC4C ${SAC4C_EXEC} -nophm -target ${TARGET} -L ${DLL_BUILD_DIR} -T ${DLL_BUILD_DIR})

# Compile sac modules with sac2c.
FOREACH (name ${SAC_MOD_SRC})
    SAC2C_COMPILE_MOD (${name} "${SAC_MOD_SRC}" "${SAC2C_DEF_FLAGS}")
ENDFOREACH (name)


# Here we create sac4c sources JUST for Sum.sac.
SET (name "Sum.sac")
SET (src "${CMAKE_CURRENT_SOURCE_DIR}/${name}")
GET_FILENAME_COMPONENT (dir "${CMAKE_CURRENT_BINARY_DIR}/${name}" DIRECTORY)
GET_FILENAME_COMPONENT (namewe ${name} NAME_WE)

SET (sac4c_out_name "sacwrapper-${namewe}")

SET (WRAPPER_SO
     "${CMAKE_CURRENT_BINARY_DIR}/${sac4c_out_name}/${TARGET_ENV}/${SBI}/lib${sac4c_out_name}${MODEXT}")
SET (WRAPPER_H
    "${CMAKE_CURRENT_BINARY_DIR}/${sac4c_out_name}.h")

# Create a call for sac4c
ADD_CUSTOM_COMMAND (
    OUTPUT  ${WRAPPER_SO} ${WRAPPER_H}
    COMMAND ${SAC4C} ${namewe} -o ${sac4c_out_name}
    MAIN_DEPENDENCY ${src}
    DEPENDS ${mod} ${tree}
    WORKING_DIRECTORY ${dir}
    COMMENT "Building cwrapper for ${name} target `${TARGET}'")
ADD_CUSTOM_TARGET (wrapper-${sac4c_out_name}-${TARGET} DEPENDS  ${WRAPPER_SO} ${WRAPPER_H})

SET (c_name   "summarizer.c")
GET_FILENAME_COMPONENT (c_namewe "${c_name}" NAME_WE)
SET (c_src    "${CMAKE_CURRENT_SOURCE_DIR}/${c_name}")
SET (c_binary "${CMAKE_CURRENT_BINARY_DIR}/${c_namewe}")

# Generate binary from C code
ADD_CUSTOM_COMMAND (
    OUTPUT ${c_binary}
    COMMAND
    ${CMAKE_C_COMPILER} -o ${c_binary}
                        ${c_src}
                        `${SAC4C} -ccflags ${namewe} -o ${sac4c_out_name} `
                        `${SAC4C} -ldflags ${namewe} -o ${sac4c_out_name} `
                        #-I${CMAKE_CURRENT_BINARY_DIR}
    #WORKING_DIRECTORY ${dir}
    MAIN_DEPENDENCY ${c_src}
    DEPENDS ${WRAPPER_SO} ${WRAPPER_H}
    IMPLICIT_DEPENDS C ${c_src}
    COMMENT "Building ${c_src} program for target `${TARGET}'")

# Make a call to the command that compiles the module a part
# of the default build process.
ADD_CUSTOM_TARGET (prog-${c_namewe}-${TARGET} ALL DEPENDS ${c_binary})

