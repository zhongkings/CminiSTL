#version 330 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inColor;
out vec3 frColor;
uniform mat4 model;
uniform mat4 projection;

void main() {
	frColor = inColor; 
	gl_Position = projection * model * vec4(inPos.x, inPos.y, inPos.z, 1);
}