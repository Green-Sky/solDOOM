cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

add_library(PureDOOM "./PureDOOM/PureDOOM.h" "./PureDOOM.c")
target_include_directories(PureDOOM SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(PureDOOM
	PRIVATE DOOM_IMPLEMENT_FILE_IO=1
	PRIVATE DOOM_IMPLEMENT_MALLOC=1
	#PRIVATE DOOM_IMPLEMENT_GETTIME=1
)

