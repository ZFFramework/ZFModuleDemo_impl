cmake_minimum_required(VERSION 3.16)
project(ZFModuleDemo_impl)
set(ZF_ROOT_PATH "${PROJECT_SOURCE_DIR}/../../../../../../ZFFramework")
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

include("${PROJECT_SOURCE_DIR}/zfprojConfig.cmake" OPTIONAL)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

file(GLOB_RECURSE ZF_SRC_FILES RELATIVE "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc/*.c"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc/*.cpp"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.c"
    "${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.cpp"
    )
if(COMMAND zfprojConfigBefore_ZFModuleDemo_impl)
    zfprojConfigBefore_ZFModuleDemo_impl(ZFModuleDemo_impl ZF_SRC_FILES)
endif()
add_library(ZFModuleDemo_impl SHARED ${ZF_SRC_FILES})
zfprojStripFILE(ZFModuleDemo_impl)
set_target_properties(ZFModuleDemo_impl PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(ZFModuleDemo_impl PUBLIC ZFLIB_ZFModuleDemo_impl=ZF_ENV_EXPORT)
if(COMMAND zfprojConfigAfter_ZFModuleDemo_impl)
    zfprojConfigAfter_ZFModuleDemo_impl(ZFModuleDemo_impl)
endif()

target_include_directories(ZFModuleDemo_impl PRIVATE "${PROJECT_SOURCE_DIR}/../../../zfsrc")

function(ZFAddLib ZF_LIB_NAME_)
    target_include_directories(ZFModuleDemo_impl PRIVATE "${ZF_ROOT_PATH}/_release/cmake/all/include")

    target_link_directories(ZFModuleDemo_impl PUBLIC "${ZF_ROOT_PATH}/_release/cmake/module/${ZF_LIB_NAME_}/lib")
    target_link_libraries(ZFModuleDemo_impl ${ZF_LIB_NAME_})
endfunction()

ZFAddLib(ZFCore)
ZFAddLib(ZF_impl)
ZFAddLib(ZFModuleDemo_lib)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfsrc/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/include"
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
install(TARGETS ZFModuleDemo_impl EXPORT ZFModuleDemo_impl
    LIBRARY DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/lib"
    ARCHIVE DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/lib"
    RUNTIME DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/lib"
    )
if(WIN32)
    execute_process(COMMAND "${ZF_ROOT_PATH}\\tools\\util\\copy_res.bat" "${PROJECT_SOURCE_DIR}\\..\\..\\..\\zfres\\" "${ZF_ROOT_PATH}\\_release\\cmake\\module\\ZFModuleDemo_impl\\zfres")
else()
    execute_process(COMMAND sh "${ZF_ROOT_PATH}/tools/util/copy_res.sh" "${PROJECT_SOURCE_DIR}/../../../zfres/" "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/zfres")
endif()

install(
    DIRECTORY "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_impl/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/all"
    )

