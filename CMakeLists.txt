cmake_minimum_required(VERSION 3.19)

project(JavaUEF CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} include)

file(GLOB SOURCES "native/*.cpp")
file(GLOB HEADERS "native/*.hpp")

add_library(Uef SHARED ${SOURCES} ${HEADERS})

if(WIN32)
    target_link_libraries(Uef ${JNI_LIBRARIES}
            "${CMAKE_SOURCE_DIR}/lib/UltralightCore.lib"
            "${CMAKE_SOURCE_DIR}/lib/AppCore.lib"
            "${CMAKE_SOURCE_DIR}/lib/Ultralight.lib"
            "${CMAKE_SOURCE_DIR}/lib/WebCore.lib"
    )
elseif(APPLE)
    target_link_libraries(Uef ${JNI_LIBRARIES}
            "${CMAKE_SOURCE_DIR}/lib/libUltralightCore.dylib"
            "${CMAKE_SOURCE_DIR}/lib/libAppCore.dylib"
            "${CMAKE_SOURCE_DIR}/lib/libUltralight.dylib"
            "${CMAKE_SOURCE_DIR}/lib/libWebCore.dylib"
    )
elseif(UNIX)
    target_link_libraries(Uef ${JNI_LIBRARIES}
            "${CMAKE_SOURCE_DIR}/lib/libUltralightCore.so"
            "${CMAKE_SOURCE_DIR}/lib/libAppCore.so"
            "${CMAKE_SOURCE_DIR}/lib/libUltralight.so"
            "${CMAKE_SOURCE_DIR}/lib/libWebCore.so"
    )
endif()