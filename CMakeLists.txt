cmake_minimum_required(VERSION 3.31)
project(GoBackNProtocol C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
if(MSVC)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(gobackn main.c)
