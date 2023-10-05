cmake_minimum_required(VERSION 3.27)
project(graphical_calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(${CMAKE_BINARY_DIR})
add_executable(graphical_calculator src/main.cpp
        exprtk/exprtk.hpp
        src/MainWindow.cpp
        src/MainWindow.h
        src/MainWindow.ui
        src/calculation.h
        src/calculation.cpp)
target_link_libraries(graphical_calculator
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
