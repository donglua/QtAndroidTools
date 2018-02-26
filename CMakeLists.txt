cmake_minimum_required(VERSION 2.8.12)

project(QtAndroidTools LANGUAGES CXX)

set(CMAKE_PREFIX_PATH ~/Qt/5.9.4/clang_64)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core)
find_package(Qt5Quick)
find_package(Qt5QuickControls2)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    mainpresenter.cpp
    mainview.cpp
    qml.qrc
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Quick
        Qt5::QuickControls2
)

