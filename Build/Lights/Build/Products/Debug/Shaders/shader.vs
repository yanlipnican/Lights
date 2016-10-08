#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

out vec3 result_position;

uniform vec2 position;

void main(void) {
    
    gl_Position.xyz = vec3(vertexPosition_modelspace.x + position.x, vertexPosition_modelspace.y + position.y, vertexPosition_modelspace.z);
    gl_Position.w = 1.0;
    
    result_position = gl_Position.xyz;
}
