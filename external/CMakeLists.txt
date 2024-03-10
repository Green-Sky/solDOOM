cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

include(FetchContent)

#if (NOT TARGET solanaceae_util)
	#FetchContent_Declare(solanaceae_util
		#GIT_REPOSITORY https://github.com/Green-Sky/solanaceae_util.git
		#GIT_TAG master
		#EXCLUDE_FROM_ALL
	#)
	#FetchContent_MakeAvailable(solanaceae_util)
#endif()

#if (NOT TARGET solanaceae_contact)
	#FetchContent_Declare(solanaceae_contact
		#GIT_REPOSITORY https://github.com/Green-Sky/solanaceae_contact.git
		#GIT_TAG master
		#EXCLUDE_FROM_ALL
	#)
	#FetchContent_MakeAvailable(solanaceae_contact)
#endif()

#if (NOT TARGET solanaceae_message3)
	#FetchContent_Declare(solanaceae_message3
		#GIT_REPOSITORY https://github.com/Green-Sky/solanaceae_message3.git
		#GIT_TAG master
		#EXCLUDE_FROM_ALL
	#)
	#FetchContent_MakeAvailable(solanaceae_message3)
#endif()

if (NOT TARGET solanaceae_plugin)
	FetchContent_Declare(solanaceae_plugin
		GIT_REPOSITORY https://github.com/Green-Sky/solanaceae_plugin.git
		GIT_TAG master
		EXCLUDE_FROM_ALL
	)
	FetchContent_MakeAvailable(solanaceae_plugin)
endif()

#if (NOT TARGET oatpp)
	#set(OATPP_INSTALL OFF CACHE BOOL "" FORCE)
	#set(OATPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	#set(OATPP_LINK_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
	#FetchContent_Declare(oatpp
		#GIT_REPOSITORY https://github.com/oatpp/oatpp.git
		#GIT_TAG master
		#EXCLUDE_FROM_ALL
	#)
	#FetchContent_MakeAvailable(oatpp)
#endif()

if (NOT TARGET PureDOOM)
	add_subdirectory(./pure_doom)
endif()

if (NOT TARGET imgui)
	FetchContent_Declare(imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui.git
		GIT_TAG d6cb3c9 # v1.90.1
		EXCLUDE_FROM_ALL
	)

	# imgui does not provide a cmake
	FetchContent_GetProperties(imgui)
	if(NOT imgui_POPULATED)
		FetchContent_Populate(imgui)

		add_library(imgui STATIC
			${imgui_SOURCE_DIR}/imgui.h
			${imgui_SOURCE_DIR}/imgui_internal.h

			${imgui_SOURCE_DIR}/imgui.cpp
			${imgui_SOURCE_DIR}/imgui_demo.cpp
			${imgui_SOURCE_DIR}/imgui_draw.cpp
			${imgui_SOURCE_DIR}/imgui_tables.cpp
			${imgui_SOURCE_DIR}/imgui_widgets.cpp
			${imgui_SOURCE_DIR}/imstb_rectpack.h
			${imgui_SOURCE_DIR}/imstb_textedit.h
			${imgui_SOURCE_DIR}/imstb_truetype.h

			${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.h
			${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
		)
		target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
		target_compile_features(imgui PUBLIC cxx_std_11)
	endif()
endif()

