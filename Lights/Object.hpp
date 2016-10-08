//
//  Object.hpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.hpp"
#include "Vectors.hpp"

class Object{
public:
    Object();
    void render();
private:
    // VAO
    GLuint VertexArrayID;
    // VBO
    GLuint vertexbuffer;
    
    GLuint shaderID;
    GLfloat* vertex_buffer_data;
    
    GLfloat width = 1.0f;
    GLfloat height = 1.0f;
    
    GLfloat x = 1.0f;
    GLfloat y = 0.0f;
    
    vec3f color = vec3f(0.5f, 0.5f, 1.0f);
    
    bool direction = true;
    
    GLint position_uniform_location;
    GLint color_uniform_location;
};

#endif /* Object_hpp */
