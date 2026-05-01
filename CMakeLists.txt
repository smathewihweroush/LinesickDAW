cmake_minimum_required(VERSION 3.31)

project(LinesickDAW)

add_executable(Linesick)

target_sources(Linesick PRIVATE src/Main.cpp)

include(FetchContent)

FetchContent_Declare(
    rtaudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
    GIT_TAG master
)

FetchContent_MakeAvailable(rtaudio)

target_link_libraries(Linesick PRIVATE rtaudio)