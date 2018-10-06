cmake_minimum_required(VERSION 3.12)
project(GAME)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES Source/*.cpp)
add_executable(GAME ${SOURCES} Source/Gui/TextLabel.hpp Source/Gui/CenteredMenu.cpp Source/Gui/CenteredMenu.hpp Source/Gui/Background.hpp)

target_link_libraries(GAME sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/Res DESTINATION ${CMAKE_BINARY_DIR})