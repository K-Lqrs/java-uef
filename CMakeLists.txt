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

include_directories("lib/ultralight-sdk-1.3.0-win-x64/include")

include_directories(${JNI_INCLUDE_DIRS})
include_directories(${JNI_HEADERS_DIR})

file(GLOB CPP_FILES "${CPP_SOURCE_DIR}/*.cpp")

add_library(JUEFNative
        src/main/cpp/JUEF.cpp
        src/main/cpp/JUEFWindow.cpp
        src/main/cpp/JUEFOverlay.cpp
        src/main/cpp/JUEFRenderer.cpp
        src/main/cpp/JUEFBitmap.cpp
        src/main/cpp/JUEFFontLoader.cpp
        src/main/cpp/JUEFFileSystem.cpp
        src/main/cpp/JUEFClipboard.cpp
        src/main/cpp/JUEFView.cpp
)

target_link_libraries(JUEFNative PRIVATE
        lib/ultralight-sdk-1.3.0-win-x64/bin/AppCore.dll
        lib/ultralight-sdk-1.3.0-win-x64/bin/Ultralight.dll
        lib/ultralight-sdk-1.3.0-win-x64/bin/UltralightCore.dll
        lib/ultralight-sdk-1.3.0-win-x64/bin/WebCore.dll
)
