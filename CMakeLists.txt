cmake_minimum_required(VERSION 3.1)

project(QtAndroidTools LANGUAGES CXX)

set(CMAKE_PREFIX_PATH ~/Qt/5.10.1/clang_64)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt5Core)
find_package(Qt5Quick)
find_package(Qt5QuickControls2)
find_package(quazip)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/mainpresenter.cpp
        src/mainview.cpp
        src/qml.qrc
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Quick
        Qt5::QuickControls2
        quazip
)

add_subdirectory(lib)
add_subdirectory(src)