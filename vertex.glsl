#version 330 core

uniform mat4 pvm_mat;

in vec3 pos;

void main() {
	gl_Position = pvm_mat * vec4(pos, 1);
}
