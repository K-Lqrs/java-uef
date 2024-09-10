cmake_minimum_required(VERSION 3.19)

project(JavaUEF CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} include)

file(GLOB SOURCES "native/*.cpp")
file(GLOB HEADERS "native/*.h")
file(GLOB LGEC_SOURCES "lgec/*.cpp")
file(GLOB LGEC_HEADERS "lgec/*.h")

add_library(Uef SHARED ${SOURCES} ${HEADERS} ${LGEC_SOURCES} ${LGEC_HEADERS})

target_link_libraries(Uef ${JNI_LIBRARIES} "../lib/UltralightCore" "../lib/AppCore" "../lib/Ultralight" "../lib/WebCore")