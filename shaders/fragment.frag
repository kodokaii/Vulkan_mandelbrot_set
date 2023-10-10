#version 450
#extension GL_ARB_separate_shader_objects : enable

#define MAX_ITER	400
#define	SQUARE(X)	X * X

layout(push_constant) uniform Push
{
	dvec2	center;
	double	radius;
	double	aspect;
} push;

layout(location = 0) in vec2	coord;

layout(location = 0) out vec4	outColor;

void main()
{
	dvec2	C	= push.center + dvec2(coord.x * push.aspect, coord.y) * push.radius;
	dvec2	Zn	= dvec2(0.0, 0.0);
	dvec2	Zn1;
	double	i	= 0;

	while (i <= MAX_ITER && SQUARE(Zn.x) + SQUARE(Zn.y) < 4)
	{
		Zn1	= dvec2(SQUARE(Zn.x) - SQUARE(Zn.y) + C.x, 2 * Zn.x * Zn.y + C.y);
		Zn	= Zn1;
		i++;
	}

	if (MAX_ITER < i)
		outColor	= vec4(0, 0, 0, 1);
	else
		outColor	= vec4(i / MAX_ITER, i / MAX_ITER, i / MAX_ITER, 1);
}
