#version 450
#extension GL_ARB_separate_shader_objects : enable

#define	SQUARE(X)	X * X

layout(push_constant) uniform Push
{
	dvec2	center;
	dvec2	Z0;
	double	radius;
	double	aspect;
	uint	iterMax;
} push;

layout(location = 0) in vec2	coord;

layout(location = 0) out vec4	outColor;

void main()
{
	dvec2	C		= push.center + dvec2(coord.x * push.aspect, coord.y) * push.radius;
	dvec2	Zn		= push.Z0;
	dvec2	Zn2		= dvec2(SQUARE(Zn.x), SQUARE(Zn.y));

	uint	iterMax	= push.iterMax;
	uint	i		= 0;

	float	brightness;
	vec3	color;

	while (i <= iterMax && Zn2.x + Zn2.y < 4)
	{
		Zn	= dvec2(Zn2.x - Zn2.y + C.x, 2 * Zn.x * Zn.y + C.y);
		Zn2	= dvec2(SQUARE(Zn.x), SQUARE(Zn.y));
		i++;
	}

	brightness	= float(i) / float(iterMax);

	if (iterMax < i)
		color	= vec3(0, 0, 0);
	else
		color	= vec3(1, 1, 1);

	outColor	= vec4(color * brightness, 1);
}
