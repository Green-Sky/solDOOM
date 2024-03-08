cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

include(FetchContent)

# TODO: move entt dep into solanaceae_contact
if (NOT TARGET EnTT::EnTT)
	FetchContent_Declare(EnTT
		GIT_REPOSITORY https://github.com/skypjack/entt.git
		GIT_TAG v3.12.2
		EXCLUDE_FROM_ALL
	)
	FetchContent_MakeAvailable(EnTT)
endif()

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

