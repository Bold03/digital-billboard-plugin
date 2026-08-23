cmake_minimum_required(VERSION 3.16)
project(DigitalBillboardPlugin CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path ke X-Plane SDK. GitHub Actions akan set ini otomatis lewat -DXPSDK_PATH=...
if(NOT DEFINED XPSDK_PATH)
    set(XPSDK_PATH "${CMAKE_SOURCE_DIR}/XPSDK")
endif()

add_library(DigitalBillboardPlugin SHARED src/plugin.cpp)

target_include_directories(DigitalBillboardPlugin PRIVATE
    ${XPSDK_PATH}/CHeaders/XPLM
    ${XPSDK_PATH}/CHeaders/Widgets
    ${XPSDK_PATH}/CHeaders/Wrappers
)

# Definisi ini bilang ke SDK: "pakai fitur sampai versi X-Plane 12 (4.0 API)"
target_compile_definitions(DigitalBillboardPlugin PRIVATE
    XPLM200 XPLM210 XPLM300 XPLM301 XPLM303 XPLM400
)

if(WIN32)
    target_compile_definitions(DigitalBillboardPlugin PRIVATE IBM=1)
    target_link_libraries(DigitalBillboardPlugin PRIVATE
        "${XPSDK_PATH}/Libraries/Win/XPLM_64.lib"
    )
    set_target_properties(DigitalBillboardPlugin PROPERTIES SUFFIX ".xpl" PREFIX "")
elseif(APPLE)
    target_compile_definitions(DigitalBillboardPlugin PRIVATE APL=1)
    target_link_options(DigitalBillboardPlugin PRIVATE "-flat_namespace" "-undefined" "dynamic_lookup")
    set_target_properties(DigitalBillboardPlugin PROPERTIES SUFFIX ".xpl" PREFIX "")
elseif(UNIX)
    target_compile_definitions(DigitalBillboardPlugin PRIVATE LIN=1)
    target_link_options(DigitalBillboardPlugin PRIVATE "-static-libgcc" "-static-libstdc++")
    set_target_properties(DigitalBillboardPlugin PROPERTIES SUFFIX ".xpl" PREFIX "")
endif()
