//
//  Shader.cpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader(char* vert_fileName, char* frag_fileName) {
    
    this->vert_fileName = vert_fileName;
    this->frag_fileName = frag_fileName;
    
    programID = glCreateProgram();

    vert_source = loadSource(vert_fileName);
    frag_source = loadSource(frag_fileName);
    
    vertexShaderObject = compile(vert_source, GL_VERTEX_SHADER);
    fragmentShaderObject = compile(frag_source, GL_FRAGMENT_SHADER);
    
    if(vertexShaderObject == -1){
        printf("Error: couldnt compile shader \"%s\"\n", vert_fileName);
        return;
    }
    if(fragmentShaderObject == -1){
        printf("Error: couldnt compile shader \"%s\"\n", frag_fileName);
        return;
    }
    
    if(!linkShaderToProgram()){
        printf("Error: couldnt attach shader \"%s\" to program\n", vert_fileName);
        return;
    }
}

std::string Shader::loadSource(char* fileName){
    
    std::string source;
    std::string line;
    std::ifstream file (fileName);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            source += line += '\n';
        }
        
        file.close();
    } else {
        file.close();
        printf("Error: couldnt find shader file \"%s\"\n", fileName);
        return "";
    }

    return source;
}

GLuint Shader::compile(std::string source, GLint shaderType){
    // create shader
    GLuint shaderObject = glCreateShader(shaderType);
    
    // convert std::string to const c_string
    char const* _source = source.c_str();
    
    // load source to shader compiler
    glShaderSource(shaderObject, 1, &_source, NULL);
    // compile
    glCompileShader(shaderObject);
    
    // check if compiled
    GLint success = GL_FALSE;
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
    
    if(success == GL_FALSE){
        return -1;
    }
    
    return shaderObject;
}

bool Shader::linkShaderToProgram(){
    glAttachShader(programID, vertexShaderObject);
    glAttachShader(programID, fragmentShaderObject);
    
    glLinkProgram(programID);
    
    GLint Result = GL_FALSE;
    
    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &Result);
    
    glDetachShader(programID, vertexShaderObject);
    glDetachShader(programID, fragmentShaderObject);
    
    glDeleteShader(vertexShaderObject);
    glDeleteShader(fragmentShaderObject);
    
    if(Result == GL_FALSE){
        return false;
    }
    
    return true;
}

GLuint Shader::getProgramId(){
    return programID;
}
