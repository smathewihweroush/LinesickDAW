cmake_minimum_required(VERSION 3.30)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

project(LinesickDAW)

# QT
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
qt_standard_project_setup(REQUIRES 6.0)

qt_add_executable(Linesick)
target_sources(Linesick PRIVATE src/Main.cpp)
set_property(TARGET Linesick PROPERTY CXX_STANDARD 20)

target_link_libraries(Linesick PRIVATE Qt6::Core)
# find_package(Qt6 REQUIRED COMPONENTS Gui)
target_link_libraries(Linesick PRIVATE Qt6::Gui)
# find_package(Qt6 REQUIRED COMPONENTS Qml)
target_link_libraries(Linesick PRIVATE Qt6::Qml)
# find_package(Qt6 REQUIRED COMPONENTS Quick)
target_link_libraries(Linesick PRIVATE Qt6::Quick)
# QT END

##add_executable(Linesick)

##target_sour   ces(Linesick PRIVATE src/Main.cpp)
##set_property(TARGET Linesick PROPERTY CXX_STANDARD 20)

# RT AUDIO

include(FetchContent)

FetchContent_Declare(
    rtaudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
    GIT_TAG master
)

FetchContent_MakeAvailable(rtaudio)
target_link_libraries(Linesick PRIVATE rtaudio)