#version 410 core

in float col;

out vec3 color;

void main() {
	color = vec3(col);
}
