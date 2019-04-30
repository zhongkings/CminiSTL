#version 330 core
out vec4 FragColor;
in vec3 frColor;

void main() {
	FragColor = vec4(frColor, 1);
}