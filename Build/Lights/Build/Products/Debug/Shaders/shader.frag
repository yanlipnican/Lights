#version 330 core

out vec3 color_out;

in vec3 result_position;

uniform vec3 color;

void main(){
    
    color_out = vec3(color.x, color.y, color.z);
    
}
