//
//  Vectors.hpp
//  Lights
//
//  Created by Jan Lipnican on 09/10/2016.
//  Copyright © 2016 Lipnican. All rights reserved.
//

#ifndef Vectors_hpp
#define Vectors_hpp

#include <stdio.h>

struct vec3f{
    vec3f(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    float x;
    float y;
    float z;
};

struct vec2f{
    vec2f(float x, float y){
        this->x = x;
        this->y = y;
    }
    
    float x;
    float y;
};

#endif /* Vectors_hpp */
