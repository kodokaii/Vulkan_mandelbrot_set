#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) out vec2	coord;

const vec2 posArray[4]	= vec2[](
		vec2(-1.0, -1.0),
		vec2(-1.0, 1.0),
		vec2(1.0, -1.0),
		vec2(1.0, 1.0)
);


void main()
{ 
	vec2	pos	= posArray[gl_VertexIndex];

	gl_Position = vec4(pos, 0.0, 1.0);
	coord		= vec2(pos.x, -pos.y);
}
