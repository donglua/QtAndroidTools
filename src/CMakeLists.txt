cmake_minimum_required(VERSION 3.9)

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
find_package(QuaZip)
find_package(zlib)
find_package(cryptopp)

