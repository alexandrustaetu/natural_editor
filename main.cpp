#include <main.hpp>
#include <glm/gtc/type_ptr.hpp>

extern World * world;
extern TextRenderer * text;
extern Menu * menu;
extern Directory * project_directory;

int main(void) {

    Grid * grid = new Grid();

    world->setMenu(menu);
    
    glm::mat4 IModelMatrix = glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)); // A bit to the left
    
    
    do {

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        world->update();
        
        if (world->changed) {
            std::cout << "[main.cpp][main]world changed\n";
            project_directory->update();
            world->changed = false;
        }

        glm::mat4 MVP = world->ProjectionMatrix * world->ViewMatrix * IModelMatrix;
        project_directory->scene.draw(&MVP);
        text->draw(&MVP);
        menu->scene.draw(&MVP);

        grid->draw(&MVP);

        glfwSwapBuffers();

    }// Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS &&
            glfwGetWindowParam(GLFW_OPENED));

    //    glDeleteProgram(box_shader);

    glfwTerminate();

//          points of a rectangle visibile to initial view
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


    return 0;
}

