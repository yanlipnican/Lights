//
//  Renderer.hpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//
//  Renderer do graphics stuff
//  It has setup and loop
//  Main Program loop is here
//

#ifndef Renderer_hpp
#define Renderer_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include "Shader.hpp"
#include "Object.hpp"

#include <vector>

class Renderer{
private:
    GLFWwindow* window;
    std::vector<Object> renderQueue;
public:
    Renderer(GLFWwindow*);
    void addToRenderQueue(Object);
    // this function will be called before loop start
    void setup();
    // render loop
    void loop();
};

#endif /* Renderer_hpp */
