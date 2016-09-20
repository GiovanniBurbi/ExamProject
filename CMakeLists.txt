cmake_minimum_required(VERSION 3.6)
project(Progetto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp Subject.h Observer.h Downloader.cpp Downloader.h GuiDownloader.cpp GuiDownloader.h FrameProgetto.cpp FrameProgetto.h Window.cpp Window.h)
add_executable(Progetto ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(Progetto ${wxWidgets_LIBRARIES})

