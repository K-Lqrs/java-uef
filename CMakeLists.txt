cmake_minimum_required(VERSION 3.10)
project(JavaUEF)

# C++17を使用するように設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# JavaとJNIを探します
find_package(JNI REQUIRED)

# Ultralightのヘッダーファイルのディレクトリを設定します
include_directories(${JNI_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/native/include)

# プラットフォームごとのライブラリディレクトリを設定します
if (WIN32)
    # Ultralight.lib が存在する正しいパスを設定
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/code/win/lib")
    set(ULTRALIGHT_CORE_LIB "UltralightCore")
    set(WEB_CORE_LIB "WebCore")
    set(ULTRALIGHT_LIB "Ultralight")
    set(APP_CORE_LIB "AppCore")
elseif (APPLE)
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/lib/mac")
    set(ULTRALIGHT_CORE_LIB "UltralightCore")
    set(WEB_CORE_LIB "WebCore")
    set(ULTRALIGHT_LIB "Ultralight")
    set(APP_CORE_LIB "AppCore")
elseif (UNIX)
    set(ULTRALIGHT_LIB_DIR "${PROJECT_SOURCE_DIR}/native/lib/linux")
    set(ULTRALIGHT_CORE_LIB "UltralightCore")
    set(WEB_CORE_LIB "WebCore")
    set(ULTRALIGHT_LIB "Ultralight")
    set(APP_CORE_LIB "AppCore")
endif ()

# Ultralightのライブラリをインポートします
add_library(Ultralight SHARED IMPORTED)

# インポートしたライブラリのプロパティを設定します
if (WIN32)
    set_target_properties(Ultralight PROPERTIES
            IMPORTED_LOCATION "${ULTRALIGHT_LIB_DIR}/${ULTRALIGHT_LIB}.dll"
            IMPORTED_IMPLIB "${ULTRALIGHT_LIB_DIR}/${ULTRALIGHT_LIB}.lib"
    )
elseif (APPLE)
    set_target_properties(Ultralight PROPERTIES
            IMPORTED_LOCATION "${ULTRALIGHT_LIB_DIR}/lib${ULTRALIGHT_LIB}.dylib"
    )
elseif (UNIX)
    set_target_properties(Ultralight PROPERTIES
            IMPORTED_LOCATION "${ULTRALIGHT_LIB_DIR}/lib${ULTRALIGHT_LIB}.so"
    )
endif ()

# ネイティブソースファイルをすべて取得します
file(GLOB NATIVE_SOURCES "${PROJECT_SOURCE_DIR}/native/src/*.cpp")

# ネイティブライブラリをビルドする
add_library(JavaUEF SHARED ${NATIVE_SOURCES})

target_link_libraries(JavaUEF ${JNI_LIBRARIES} "${ULTRALIGHT_LIB_DIR}/${ULTRALIGHT_LIB}.lib" "${ULTRALIGHT_LIB_DIR}/${ULTRALIGHT_CORE_LIB}.lib" "${ULTRALIGHT_LIB_DIR}/${APP_CORE_LIB}.lib" "${ULTRALIGHT_LIB_DIR}/${WEB_CORE_LIB}.lib")

# 出力ディレクトリを設定します
set_target_properties(JavaUEF PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/native/out
)
