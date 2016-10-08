//
//  Shader.hpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//
//  Class to load shader source from file, compile it, and return shaderProgram ID
//

#ifndef Shader_hpp
#define Shader_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

class Shader{
public:
    Shader(char*, char*);
    GLuint getProgramId();
private:

    std::string loadSource(char*);
    GLuint compile(std::string, GLint);
    bool linkShaderToProgram();
    
    char* vert_fileName;
    char* frag_fileName;
    
    std::string vert_source;
    std::string frag_source;
    
    GLuint vertexShaderObject;
    GLuint fragmentShaderObject;
    
    GLuint programID;
    
};

#endif /* Shader_hpp */
