cmake_minimum_required(VERSION 3.0)

project(nsf-setsystem LANGUAGES C)

add_executable(nsf-setsystem main.c)

install(TARGETS nsf-setsystem RUNTIME DESTINATION bin)
