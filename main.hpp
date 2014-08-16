// Include standard headers
#define DEBUG_ENABLED 1
#include <stdio.h>
#include <memory>
#include <stdlib.h>
#include <fstream>
#include <array>
#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <cfloat>
#include <string>
#include <bitset>
#include <cmath> 
#include <utility>
#include <typeinfo>
#include <math.h>

// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GL/glfw.h>

std::vector<GLfloat> cube_shape({
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f
});

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include <glm/gtc/type_ptr.hpp>
#include <common/shader_utils.hpp>


#include <boost/filesystem.hpp>
#include <boost/unordered_map.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <common/handle.hpp>

#include <common/space/object3d.hpp>
#include <common/space/grid.hpp>

Object3dProperties props;
std::shared_ptr<Object3dExpanded> DebugFrame = std::make_shared<Object3dExpanded>(&props);


#include <common/debug.hpp>
NEGLDebugDrawer * physicsdebug = new NEGLDebugDrawer();
#include <common/space/physics.hpp>
#include <common/space/scene.hpp>
#include <common/input/menu.hpp>
//#include <common/environment/debug_frame.hpp>
//DebugFrame * debugFrame = new DebugFrame();

#include <common/environment/world.hpp>
World * world = new World();
#include <common/text/word.cpp>
#include <common/text/text.hpp>
Letter * z = new Letter(55);
TextRenderer * text = new TextRenderer();
Menu * menu = new Menu();
//#include <common/filesystem/file.hpp>
//File * file = new File();


#include <common/filesystem/disk.hpp>
#include <common/filesystem/directory.hpp>
Directory * project_directory = new Directory("/var/www/symphony-2");


#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>

#include <boost/iostreams/stream.hpp>

