#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <math.h>

#define PI 3.14159265359

typedef struct		s_vec3
{
	float		x;
	float		y;
	float		z;
}					t_vec3;

typedef struct		s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}					t_vec4;

typedef struct		s_mat4
{
	float		m[4][4];
}					t_mat4;

void		make_rescale(t_mat4 *to_scale, t_vec3 *vector);
t_mat4		create_mat4(float homogene);
t_mat4		make_translation(t_vec3 *src);
t_mat4		m4_x_m4(t_mat4 *a, t_mat4 *b);
t_mat4		matrix_scale(float value);
t_mat4		make_rot_x(float degree);
t_mat4		make_rot_y(float degree);
t_mat4		make_rot_z(float degree);
#endif