//
//  Object.cpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//

#include "Object.hpp"

Object::Object(){
    
    Shader* shader = new Shader("Shaders/shader.vs", "Shaders/shader.frag");
    shaderID = shader->getProgramId();
    delete shader;
    
    position_uniform_location = glGetUniformLocation(shaderID, "position");
    color_uniform_location = glGetUniformLocation(shaderID, "color");
    
    GLfloat data[] =  {
        -1.0f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -1.0f,  0.25f, 0.0f,
        
        -1.0f, 0.25f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.25f, 0.0f,
        
    };
    
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    
}

void Object::render(){
    
    glUseProgram(shaderID);
    
    if(x < 0.0f){
        direction = false;
    }
    
    if(x > 1.5f){
        direction = true;
    }
    
    if(direction){
        x-=0.01f;
    } else x+=0.01f;
    
    glUniform2f(position_uniform_location, x, y);
    glUniform3f(color_uniform_location, color.x, color.y, color.z);
    
    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
    
}
