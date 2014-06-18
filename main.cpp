#include <main.hpp>
#include <glm/gtc/type_ptr.hpp>

World * world = new World();
TextRenderer * text = new TextRenderer(world->physics);
Menu * menu = new Menu(text,world->physics);

int main(void) {
    world->setMenu(menu);
    
    glm::mat4 IModelMatrix = glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)); // A bit to the left
    Directory project_directory("/var/www/symphony-2", world->physics, text);
    
    do {

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        world->update();
        
        if (world->changed) {
            project_directory.update();
            world->changed = false;
        }

        glm::mat4 MVP = world->ProjectionMatrix * world->ViewMatrix * IModelMatrix;
        project_directory.scene.draw(&MVP);
        text->draw(&MVP);
        menu->scene.draw(&MVP);

        glfwSwapBuffers();

    }// Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS &&
            glfwGetWindowParam(GLFW_OPENED));

    //    glDeleteProgram(box_shader);

    glfwTerminate();

    
    
//    GLuint file_lines_buffer;
//        glGenBuffers(1, &file_lines_buffer);
//        static const GLfloat test_vertex_data[] = {
//            -0.1f, -0.1f, 1.0f,
//            0.1f, -0.1f, 1.0f,
//            -0.1f, 0.1f, 1.0f,
//            0.1f, -0.1f, 1.0f,
//            0.1f, 0.1f, 1.0f,
//            -0.1f, 0.1f, 1.0f
//        };
//        
//        
//        
//        GLuint tbuffer;
//        glGenBuffers(1, &tbuffer);
//        glBindBuffer(GL_ARRAY_BUFFER, tbuffer);
//        glBufferData(GL_ARRAY_BUFFER, sizeof (test_vertex_data), test_vertex_data, GL_STATIC_DRAW);
//
//        std::vector<GLfloat> file_lines;
//
//        GLuint linesbuffer;
//        glGenBuffers(1, &linesbuffer);
//
//
//        ///////////////////////////instancing////////////////////////////////////////
//
//        //create shaders
//        GLuint box_shader = LoadShaders("box.vertexshader", "box.fragmentshader");
//
//        GLuint mvp_uniform = glGetUniformLocation(box_shader, "MVP");
//
//        glUseProgram(box_shader);
//
//        glBindBuffer(GL_ARRAY_BUFFER, tbuffer);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(
//                0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//
//        glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, &MVP[0][0]);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        glDisableVertexAttribArray(0);
//
//        glBindBuffer(GL_ARRAY_BUFFER, linesbuffer);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(
//                0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//
//        glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, &MVP[0][0]);
//
//        glDrawArrays(GL_LINES, 0, file_lines.size() / 3);
//        glDisableVertexAttribArray(0);
    
    
    
    
    
    
    
    return 0;
}

