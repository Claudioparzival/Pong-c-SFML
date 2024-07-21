cmake_minimum_required(VERSION 3.27)
project(PONG-c-SFML)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR C:/Users/Claudio/.vcpkg-clio/vcpkg/installed/x64-mingw-dynamic/share)
include(fetchcontent)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE()
add_executable(Pong-c-SFML
        pong.cpp)
find_package(SFML COMPONENTS graphics system window CONFIG REQUIRED)
target_link_libraries(Pong-c-SFML sfml-graphics sfml-system sfml-window)