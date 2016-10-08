//
//  main.cpp
//  Lights
//
//  Created by Jan Lipnican on 05/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//
//  Just window init and stuff here
//  Renderer is initialized from here
//

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Renderer.hpp"


int main(int argc, const char * argv[]) {
    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return false;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(640, 420, "Lights", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();
    
    
    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    
    // setup renderer
    Renderer* renderer = new Renderer(window);
    renderer->setup();
    glClearColor(0.5f, 0.5f, 0.7f, 0.0f);
    while(!glfwWindowShouldClose(window)) {
        renderer->loop();
    }
    
    glfwTerminate();
    
    return 0;
}
