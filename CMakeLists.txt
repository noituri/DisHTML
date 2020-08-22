cmake_minimum_required(VERSION 3.17)
project(DisHTML)

set(CMAKE_CXX_STANDARD 20)
set(USE_OPENSSL 1)

add_executable(DisHTML main.cpp third_party/tinyxml2/tinyxml2.cpp third_party/tinyxml2/tinyxml2.h client.cpp client.h command.cpp command.h)

add_subdirectory(third_party/sleepy-discord)
target_link_libraries(DisHTML sleepy-discord)