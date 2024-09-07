cmake_minimum_required(VERSION 3.19)

project(JavaUEF CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} include)

file(GLOB SOURCES "native/*.cpp")
add_library(Uef SHARED ${SOURCES})

target_link_libraries(Uef ${JNI_LIBRARIES} "../lib/UltralightCore" "../lib/AppCore" "../lib/Ultralight" "../lib/WebCore")