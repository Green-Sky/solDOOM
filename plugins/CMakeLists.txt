cmake_minimum_required(VERSION 3.9...3.24 FATAL_ERROR)

add_library(plugin_doom_imgui MODULE
	./plugin_doom_imgui.cpp
)
target_compile_features(plugin_doom_imgui PUBLIC cxx_std_17)
set_target_properties(plugin_doom_imgui PROPERTIES
	C_VISIBILITY_PRESET hidden
)
target_link_libraries(plugin_doom_imgui PUBLIC
	solDOOM_imgui
	solanaceae_plugin
)

########################################

