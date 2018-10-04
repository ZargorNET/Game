cmake_minimum_required(VERSION 3.12)
project(GAME)


set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(GAME Source/Main.cpp Source/GameWindow.cpp Source/GameWindow.hpp Source/Util/Singleton.hpp Source/Application.cpp Source/Application.hpp Source/State/IStateBase.hpp Source/State/MainMenu.cpp Source/State/MainMenu.hpp Source/GameRenderer.cpp Source/GameRenderer.hpp Source/Gui/Menu.cpp Source/Gui/Menu.hpp Source/Gui/Component.hpp Source/Gui/Button.cpp Source/Gui/Button.hpp Source/Gui/TextButton.cpp Source/Gui/TextButton.hpp)
target_link_libraries(GAME sfml-graphics sfml-audio)