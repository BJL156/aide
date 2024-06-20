#version 330 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 outTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    outTexCoords = texCoords;
    gl_Position = proj * view * model * vec4(vertex, 1.0);
}