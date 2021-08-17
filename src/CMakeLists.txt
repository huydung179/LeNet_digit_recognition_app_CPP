cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(custom_ops)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(Torch_DIR /home/huydung/cpplib/libtorch/share/cmake/Torch)
find_package(Torch REQUIRED)
set(Qt5_DIR /usr/lib/x86_64-linux-gnu/cmake/qt5)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(OpenCV_DIR /opt/opencv/build)
find_package( OpenCV REQUIRED )
include_directories( "${OpenCV_INCLUDE_DIRS}" )

add_executable(inference
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    scribblearea.cpp
    scribblearea.h
    digitprediction.cpp
    digitprediction.h
    )

target_link_libraries(inference
    "${TORCH_LIBRARIES}"
    "${OpenCV_LIBS}"
    Qt5::Widgets
    )

set_property(TARGET inference PROPERTY CXX_STANDARD 14)
