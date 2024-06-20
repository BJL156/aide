#version 330 core

out vec4 fragColor;

in vec2 outTexCoords;

uniform sampler2D texture_diffuse1;

void main() {
    fragColor = texture(texture_diffuse1, outTexCoords);
}