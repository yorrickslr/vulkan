cmake_minimum_required (VERSION 2.6)
project(VulkanWonderland)

# compiler flags
if (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif (UNIX)


# additional options
option(GLFW_BUILD_DOCS     OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS    OFF)
option(GLFW_INSTALL        OFF)


# library- and subdirectories
if (MSVC)
	link_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/build/src/Release")
	link_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/vulkan/Bin")
endif (MSVC)
if (UNIX)
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw")
endif (UNIX)


# include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/include")
if (MSVC)
	include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/vulkan/Include")
endif (MSVC)
if (UNIX)
	include_directories("/usr/include/vulkan")
endif (UNIX)


# executables
add_executable(VulkanWonderland main.cpp)


#libraries
if (MSVC)
	target_link_libraries(VulkanWonderland "glfw3dll.lib")
	target_link_libraries(VulkanWonderland "vulkan-1.lib")
endif (MSVC)
if (UNIX)
	target_link_libraries(VulkanWonderland glfw ${GLFW_LIBRARIES})
	target_link_libraries(VulkanWonderland vulkan)
endif (UNIX)


# additional tasks
if (MSVC)
	add_custom_target(CopyBinaries
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/build/src/Release/glfw3.dll ${CMAKE_BINARY_DIR}/Release
	)
	add_dependencies(VulkanWonderland CopyBinaries)
endif (MSVC)
