cmake_minimum_required(VERSION 3.9...3.24 FATAL_ERROR)

project(solanaceae)

# we need:
# - texture uploader (refactor from tomato with streaming)
# - netcode abstraction
# - tox netcode impl? (share with toxic games?)
# - imgui embedded window an inputs?
# - pure doom

add_library(solDOOM
	./solanaceae/doom.hpp
	./solanaceae/doom.cpp
)

target_include_directories(solDOOM PUBLIC .)
target_compile_features(solDOOM PUBLIC cxx_std_17)
target_link_libraries(solDOOM PUBLIC
	PureDOOM
	#httplib::httplib
	#nlohmann_json::nlohmann_json

	#solanaceae_util
)

#########################################

add_library(solDOOM_imgui
	./solanaceae/doom_imgui.hpp
	./solanaceae/doom_imgui.cpp
)

target_include_directories(solDOOM_imgui PUBLIC .)
target_link_libraries(solDOOM_imgui PUBLIC
	solDOOM
	imgui
)

