cmake_minimum_required(VERSION 3.10)
project(JavaUEF)

# JavaとJNIを探します
find_package(JNI REQUIRED)

# Ultralightのヘッダーファイルのディレクトリを設定します
include_directories(${JNI_INCLUDE_DIRS})

# native/includeディレクトリ内のすべてのヘッダーファイルを含めます
include_directories(${PROJECT_SOURCE_DIR}/native/include)

# プラットフォームごとのライブラリディレクトリを設定します
if (WIN32)
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/lib/win")
    set(ULTRALIGHT_LIB "Ultralight")
elseif (APPLE)
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/lib/mac")
    set(ULTRALIGHT_LIB "Ultralight")
elseif (UNIX)
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/lib/linux")
    set(ULTRALIGHT_LIB "Ultralight")
endif ()

# ネイティブソースファイルをすべて取得します
file(GLOB NATIVE_SOURCES "${PROJECT_SOURCE_DIR}/native/src/*.cpp")

# ネイティブライブラリをビルドする
add_library(JavaUEF SHARED ${NATIVE_SOURCES})

add_library(ultralight SHARED IMPORTED)

# ライブラリディレクトリとリンクするライブラリを設定します
target_link_libraries(JavaUEF ${JNI_LIBRARIES})
target_link_libraries(JavaUEF ${ULTRALIGHT_LIB_DIR}/${ULTRALIGHT_LIB})

# 出力ディレクトリを設定します
set_target_properties(JavaUEF PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/native/out
)
