#include "scene.hpp"
#include <iostream>
#include <math.h>
#include <common/environment/world.hpp>
extern World * world;

Scene::Scene() {
}

ArraysInstanced::ArraysInstanced():
    position_uniform(1),
    scale_uniform(2),
    color_uniform(3),
    indices_uniform(4),
    borders_uniform(0)
{
    this->physics = world->physics;
}

void ArraysInstanced::setUp(std::vector<GLfloat> * pattern) {

    points_count = pattern->size();

    shader = LoadShaders("instancing.vertexshader", "instancing.fragmentshader");
    borders_shader = LoadShaders("box.vertexshader", "box.fragmentshader");
    
    borders_mvp_uniform = glGetUniformLocation(borders_shader, "MVP");
    mvp_uniform = glGetUniformLocation(shader, "MVP");

    glUseProgram(shader);

    glGenBuffers(1, &indices_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, indices_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof (GLfloat) * pattern->size(), pattern->data(), GL_STATIC_DRAW);

    glGenBuffers(1, &positions_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, positions_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &scales_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, scales_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * scales.size(), scales.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &colors_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, colors_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &borders_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, borders_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * borders.size(), borders.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, indices_buffer);
    glEnableVertexAttribArray(indices_uniform);
    glVertexAttribPointer(indices_uniform,3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLsizei datasize = sizeof ( glm::vec3);
    char* pointer = 0; //no other components
    GLuint divisor = 1; //instanced
    //positions
    glBindBuffer(GL_ARRAY_BUFFER, positions_buffer);
    glEnableVertexAttribArray(position_uniform);
    glVertexAttribPointer(position_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(position_uniform, divisor);

    //scales
    glBindBuffer(GL_ARRAY_BUFFER, scales_buffer);
    glEnableVertexAttribArray(scale_uniform);
    glVertexAttribPointer(scale_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(scale_uniform, divisor);

    //colors
    glBindBuffer(GL_ARRAY_BUFFER, colors_buffer);
    glEnableVertexAttribArray(color_uniform);
    glVertexAttribPointer(color_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(color_uniform, divisor);
}

void ArraysInstanced::draw(glm::mat4 * mvp) {
    
    updateSceneData();

    glUseProgram(shader);

    glBindVertexArray(vao);

    glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, glm::value_ptr(*mvp));

    glDrawArraysInstanced(GL_TRIANGLES, 0, points_count/3, positions.size());

    glDisableVertexAttribArray(mvp_uniform);

    //Does not work, the cubes shapes will disappear
//    glDisableVertexAttribArray(position_uniform);
//    glDisableVertexAttribArray(scale_uniform);
//    glDisableVertexAttribArray(color_uniform);
//    glDisableVertexAttribArray(indices_uniform);

    drawBorders(mvp);
}

void ArraysInstanced::updateSceneData() {
    if (changed) {
        glBindBuffer(GL_ARRAY_BUFFER, borders_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * borders.size(), borders.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, positions_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, scales_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * scales.size(), scales.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, colors_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);
        changed = false;
    }
}

void ArraysInstanced::drawBorders(glm::mat4 * mvp) {
        
        glUseProgram(borders_shader);

        glBindBuffer(GL_ARRAY_BUFFER, borders_buffer);
        glEnableVertexAttribArray(borders_uniform);
        glVertexAttribPointer(borders_uniform, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

        glUniformMatrix4fv(borders_mvp_uniform, 1, GL_FALSE, glm::value_ptr(*mvp) );
      
        glDrawArrays(GL_LINES, 0, borders.size() );
        glDisableVertexAttribArray(borders_uniform);
}

//void ArraysInstanced::setPhysics(btDiscreteDynamicsWorld* physics) {
//    this->physics = physics;
//}

/*
void ArraysInstanced::place(SpatialObjectExpanded object) {
    if (object->parent) {

        int enclosing_width, enclosing_height,side_length;
        side_length = enclosing_width = enclosing_height = ceil(sqrt(object->siblings_count));
        
        if(side_length > 10){
            enclosing_width = enclosing_height = side_length = 10;
        } else if (side_length < 5){
            side_length = object->siblings_count;
            enclosing_height = 1;
        }
        
        
        int position_y = floor(object->order/enclosing_width) + 1;
        int position_x = object->order % enclosing_width + 1;
        GLfloat real_enclosing_width = enclosing_width * (object->dimension.width + object->margin.left + object->margin.right) - object->margin.right;
        GLfloat real_enclosing_height = enclosing_height * (object->dimension.height + object->margin.top + object->margin.bottom) - object->margin.bottom;
        
        GLfloat real_position_x = position_x * (object->dimension.width + object->margin.left + object->margin.right) - (object->margin.right+object->margin.left);
        GLfloat real_position_y = position_y * (object->dimension.height + object->margin.top + object->margin.bottom) - (object->margin.bottom+object->margin.top);
        
        glm::vec3 parent_coords = object->parent->coords;
        margins parent_margins = object->parent->margin;
        dimensions parent_dimensions = object->parent->dimension;
        
        object->origin = object->parent->coords;

        object->destination.z = parent_coords.z -
                parent_margins.back -
                parent_dimensions.depth
                ;
        object->destination.x = real_position_x;
        object->destination.y = real_position_y;
        
        object->coords = object->destination;

    }

    //////////test if requested space is empty
    //    btCollisionShape* boxCollisionShape = new btBoxShape(btVector3(1.2, 1.2, 1.2));
    //    btPairCachingGhostObject* ghostObject = new btPairCachingGhostObject();
    //    btTransform trans;
    //    trans.setIdentity();
    //    trans.setOrigin(btVector3(1.2, 1.2, 1.2));
    //    ghostObject->setWorldTransform(trans);
    //    ghostObject->setCollisionShape(boxCollisionShape);
    //    ghostObject->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT | btCollisionObject::CF_NO_CONTACT_RESPONSE);
    //
    //    this->physics->addCollisionObject(ghostObject, 1, 2);
    //
    //    //                btManifoldArray manifoldArray;
    //    //                btBroadphasePairArray& pairArray = ghostObject->getOverlappingPairCache()->getOverlappingPairArray();
    //    while (ghostObject->getOverlappingPairCache()->getOverlappingPairArray().size() > 0) {
    //        //iterate over space positions, and see which slot is free
    //        this->physics->removeCollisionObject(ghostObject);
    //        trans.setOrigin(btVector3(1.2, 1.2, 1.2));
    //        ghostObject->setWorldTransform(trans);
    //        this->physics->addCollisionObject(ghostObject, 1, 2);
    //    }
    //    this->physics->removeCollisionObject(ghostObject);

    //this is to get the real colision, previous will get bounding box, i think.
    //                for (int i = 0; i < numPairs; i++) {
    //                    manifoldArray.clear();
    //
    //                    const btBroadphasePair& pair = pairArray[i];
    //
    //                    //unless we manually perform collision detection on this pair, the contacts are in the dynamics world paircache:
    //                    btBroadphasePair* collisionPair = dynamicsWorld->getPairCache()->findPair(pair.m_pProxy0, pair.m_pProxy1);
    //                    if (!collisionPair)
    //                        continue;
    //
    //                    if (collisionPair->m_algorithm)
    //                        collisionPair->m_algorithm->getAllContactManifolds(manifoldArray);
    //                    //cout << manifoldArray.size() << endl;
    //                    for (int j = 0; j < manifoldArray.size(); j++) {
    //                        btPersistentManifold* manifold = manifoldArray[j];
    //                        btScalar directionSign = manifold->getBody0() == ghostObject ? btScalar(-1.0) : btScalar(1.0);
    //                        for (int p = 0; p < manifold->getNumContacts(); p++) {
    //                            const btManifoldPoint&pt = manifold->getContactPoint(p);
    //                            if (pt.getDistance() < 0.f) {
    //                                const btVector3& ptA = pt.getPositionWorldOnA();
    //                                const btVector3& ptB = pt.getPositionWorldOnB();
    //                                const btVector3& normalOnB = pt.m_normalWorldOnB;
    //                                cout << "burned";
    //                                /// work here
    //                            }
    //                        }
    //                    }
    //                }

    ////////// end test if requested space is empty
}
*/

//void ArraysInstanced::changeElement(SpatialObjectExpanded element) {
//    this->positions[element->sceneIndex] = element->coords;
//    this->scales[element->sceneIndex] = glm::vec3(
//            element->dimension.width,
//            element->dimension.height,
//            element->dimension.depth
//            );
//    this->colors[element->sceneIndex] = element->color;
//    this->changed = true;
//}
