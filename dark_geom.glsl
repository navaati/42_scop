#version 410 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

out float col;

void main() {
	float prim_col = fract(float(gl_PrimitiveIDIn) / 7) * 0.8;

	gl_Position = gl_in[0].gl_Position;
	col = prim_col;
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	col = prim_col;
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;
	col = prim_col;
	EmitVertex();

	EndPrimitive();
}
