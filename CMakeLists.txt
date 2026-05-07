cmake_minimum_required(VERSION 3.31)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

project(LinesickDAW)

add_executable(Linesick)

target_sources(Linesick PRIVATE src/Main.cpp)
set_property(TARGET Linesick PROPERTY CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    rtaudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
    GIT_TAG master
)

FetchContent_MakeAvailable(rtaudio)

target_link_libraries(Linesick PRIVATE rtaudio)