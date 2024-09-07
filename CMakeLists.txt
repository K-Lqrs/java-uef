cmake_minimum_required(VERSION 3.19)

project(JavaUEF CXX)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} include)

file(GLOB SOURCES "native/*.cpp")
add_library(Uef SHARED ${SOURCES})

if(WIN32)
    target_link_libraries(Uef ${JNI_LIBRARIES} "lib/UltralightCore.lib" "lib/AppCore.lib" "lib/Ultralight.lib" "lib/WebCore.lib")
elseif(APPLE)
    target_link_libraries(Uef ${JNI_LIBRARIES} "bin/mac/libUltralightCore.dylib" "bin/mac/libAppCore.dylib" "bin/mac/libUltralight.dylib" "bin/mac/libWebCore.dylib")
elseif(UNIX)
    target_link_libraries(Uef ${JNI_LIBRARIES} "bin/linux/libUltralightCore.so" "bin/linux/libAppCore.so" "bin/linux/libUltralight.so" "bin/linux/libWebCore.so")
endif()