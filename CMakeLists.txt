# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (Natural)
set(CMAKE_BUILD_TYPE Debug)
find_package(OpenGL REQUIRED)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "asfYour Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")

include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(GMP REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(
	#external/AntTweakBar-1.16/include/
	external/glfw-2.7.6/include/
	external/glm-0.9.4.0/
	external/freetype-2.5.2/include
	external/glew-1.9.0/include/
	#external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/
	.
)
message(STATUS ${GMP_LIBRARIES})
set(ALL_LIBS
	${OPENGL_LIBRARY}
        ${GMP_LIBRARIES}
        CGAL
        ${Boost_LIBRARIES}
        ${Boost_FILESYSTEM_LIBRARY}
	GLFW_276
	GLEW_190
        BulletDynamics
        BulletCollision
        LinearMath
        freetype
        
        ${FREETYPE_LIBRARY}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
        -frounding-math 
        
)


# Tutorial 6
add_executable(natural
	main.hpp
	main.cpp
	common/handle.cpp
	common/handle.hpp
#	common/filesystem/file.hpp
#	common/filesystem/file.cpp
	common/text/word.cpp
	common/text/word.hpp
	common/filesystem/disk.hpp
	common/filesystem/disk.cpp
	common/filesystem/directory.hpp
	common/filesystem/directory.cpp
	common/debug.hpp
	common/debug.cpp
	common/shader.hpp
	common/shader.cpp
	common/controls.hpp
	common/controls.cpp
	
	common/space/object3d.cpp
	common/space/object3d.hpp
        common/space/grid.cpp
        common/space/grid.hpp
        common/space/physics.cpp
	common/space/physics.hpp
	common/environment/world.cpp
	common/environment/world.hpp
	common/environment/debug_frame.cpp
	common/environment/debug_frame.hpp
	common/environment/debug_world_helper.hpp
	common/space/scene.cpp
	common/space/scene.hpp
	common/text/canvas.cpp
	common/text/canvas.hpp
	common/text/text.cpp
	common/text/text.hpp
	common/texture.cpp
	common/texture.hpp
	
	common/shader_utils.cpp
	common/shader_utils.hpp

	common/input/menu.cpp
	common/input/menu.hpp
	
)
target_link_libraries(natural
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(natural PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
create_target_launcher(natural WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/")




SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/src/.*shader$" )
SOURCE_GROUP(sources REGULAR_EXPRESSION ".*/src/.cpp" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

add_custom_command(TARGET natural PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:natural>)

add_custom_command(
   TARGET natural POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/src${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/src/"
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/shaders/"
)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

