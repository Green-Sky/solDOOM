cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

add_library(PureDOOM INTERFACE "./PureDOOM/PureDOOM.h")
target_include_directories(PureDOOM SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

