#include "scene.hpp"
#include <iostream>
#include <math.h>
#include <common/environment/world.hpp>
extern World * world;

Scene::Scene() {
}

ArraysInstanced::ArraysInstanced() {
    this->physics = world->physics;
}

void ArraysInstanced::SetIndices(std::vector<GLfloat> * pattern) {

    this->shader = LoadShaders("instancing.vertexshader", "instancing.fragmentshader");
    this->borders_shader = LoadShaders("box.vertexshader", "box.fragmentshader");
        
    
    glUseProgram(this->shader);

    this->mvp_uniform = glGetUniformLocation(this->shader, "MVP");
    this->position_uniform = 1; 
    this->scale_uniform = 2; 
    this->color_uniform = 3; 

    glGenBuffers(1, &this->positions_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->positions_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->positions.size(), this->positions.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->scales_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->scales_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->scales.size(), this->scales.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->colors_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->colors_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->colors.size(), this->colors.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &this->borders_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->borders_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->borders.size(), this->borders.data(), GL_STATIC_DRAW);


    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    GLsizei datasize = sizeof ( glm::vec3);
    char* pointer = 0; //no other components
    GLuint divisor = 1; //instanced
    //positions
    glBindBuffer(GL_ARRAY_BUFFER, this->positions_buffer);
    glEnableVertexAttribArray(this->position_uniform);
    glVertexAttribPointer(this->position_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(this->position_uniform, divisor);


    //scales
    glBindBuffer(GL_ARRAY_BUFFER, this->scales_buffer);
    glEnableVertexAttribArray(this->scale_uniform);
    glVertexAttribPointer(this->scale_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(this->scale_uniform, divisor);

    //colors
    glBindBuffer(GL_ARRAY_BUFFER, this->colors_buffer);
    glEnableVertexAttribArray(this->color_uniform);
    glVertexAttribPointer(this->color_uniform,
            3, GL_FLOAT, GL_FALSE,
            datasize, pointer);
    glVertexAttribDivisor(this->color_uniform, divisor);


    glGenBuffers(1, &this->indices_buffer);

    glBindBuffer(GL_ARRAY_BUFFER, this->indices_buffer);

    glBufferData(GL_ARRAY_BUFFER, pattern->size() * sizeof (GLfloat), pattern->data(), GL_STATIC_DRAW);

    this->points_count = pattern->size();
}

void ArraysInstanced::draw(glm::mat4 * mvp) {
    
    this->updateSceneData();

    glUseProgram(this->shader);

    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->indices_buffer);

    glUniformMatrix4fv(this->mvp_uniform, 1, GL_FALSE, glm::value_ptr(*mvp));
    glEnableVertexAttribArray(this->mvp_uniform);
    glVertexAttribPointer(
            this->mvp_uniform,
            3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glDrawArraysInstanced(GL_TRIANGLES, 0, this->points_count/3, this->positions.size());
    glDisableVertexAttribArray(this->mvp_uniform);
    
    this->drawBorders(mvp);
}

void ArraysInstanced::updateSceneData() {
    if (this->changed) {
        glBindBuffer(GL_ARRAY_BUFFER, this->borders_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->borders.size(), this->borders.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, this->positions_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->positions.size(), this->positions.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, this->scales_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->scales.size(), this->scales.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, this->colors_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof ( glm::vec3) * this->colors.size(), this->colors.data(), GL_STATIC_DRAW);
        this->changed = false;
    }
}

void ArraysInstanced::drawBorders(glm::mat4 * mvp) {
        
        GLuint mvp_uniform = glGetUniformLocation(this->borders_shader, "MVP");
        glUseProgram(this->borders_shader);

        glBindBuffer(GL_ARRAY_BUFFER, this->borders_buffer);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
                0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

        glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, glm::value_ptr(*mvp) );
      
        glDrawArrays(GL_LINES, 0, this->borders.size() );
        glDisableVertexAttribArray(0);
}

//void ArraysInstanced::setPhysics(btDiscreteDynamicsWorld* physics) {
//    this->physics = physics;
//}

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
