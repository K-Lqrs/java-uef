cmake_minimum_required(VERSION 3.10)

project(JUEF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

set(JAVA_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/main/java")
set(CPP_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/main/cpp")

file(GLOB JAVA_FILES "${JAVA_SOURCE_DIR}/net/rk4z/juef/*.java")
set(JNI_HEADERS_DIR "${CMAKE_BINARY_DIR}/generated")
file(MAKE_DIRECTORY ${JNI_HEADERS_DIR})

add_custom_command(
        OUTPUT ${JNI_HEADERS_DIR}/net_rk4z_juef_JUEF.h
        COMMAND ${Java_JAVAC_EXECUTABLE} -d ${CMAKE_BINARY_DIR}/classes -h ${JNI_HEADERS_DIR} ${JAVA_FILES}
        DEPENDS ${JAVA_FILES}
        COMMENT "Generating JNI headers and compiling Java classes"
)

include_directories(${JNI_INCLUDE_DIRS} ${JNI_HEADERS_DIR} "${PROJECT_SOURCE_DIR}/lib/ultralight-sdk-1.3.0-win-x64/include")

file(GLOB CPP_FILES "${CPP_SOURCE_DIR}/*.cpp")

add_library(JUEFNative SHARED ${CPP_FILES} ${JNI_HEADERS_DIR}/net_rk4z_juef_JUEF.h)

target_link_libraries(JUEFNative PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/ultralight-sdk-1.3.0-win-x64/bin/AppCore.dll"
        "${PROJECT_SOURCE_DIR}/lib/ultralight-sdk-1.3.0-win-x64/bin/Ultralight.dll"
        "${PROJECT_SOURCE_DIR}/lib/ultralight-sdk-1.3.0-win-x64/bin/UltralightCore.dll"
        "${PROJECT_SOURCE_DIR}/lib/ultralight-sdk-1.3.0-win-x64/bin/WebCore.dll"
)
