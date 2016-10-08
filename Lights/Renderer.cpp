//
//  Renderer.cpp
//  Lights
//
//  Created by Jan Lipnican on 08/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//

#include "Renderer.hpp"


Renderer::Renderer(GLFWwindow* window){
    this->window = window;
}

void Renderer::setup() {
    Object test = Object();
    addToRenderQueue(test);
}

void Renderer::loop(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwPollEvents();
    
    for(int i = 0; i < renderQueue.size(); i++){
        renderQueue.at(i).render();
    }
    
    glfwSwapBuffers(window);
}

void Renderer::addToRenderQueue(Object object){
    renderQueue.push_back(object);
}

