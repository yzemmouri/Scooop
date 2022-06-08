#include "../include/mathematics.h"

void		make_rescale(t_mat4 *to_scale, t_vec3 *vector)
{
	to_scale->m[0][0] = vector->x;
	to_scale->m[0][1] = 0.0f;
	to_scale->m[0][2] = 0.0f;
	to_scale->m[0][3] = 0.0f;
	to_scale->m[1][0] = 0.0f;
	to_scale->m[1][1] = vector->y;
	to_scale->m[1][2] = 0.0f;
	to_scale->m[1][3] = 0.0f;
	to_scale->m[2][0] = 0.0f;
	to_scale->m[2][1] = 0.0f;
	to_scale->m[2][2] = vector->z;
	to_scale->m[2][3] = 0.0f;
	to_scale->m[3][0] = 0.0f;
	to_scale->m[3][1] = 0.0f;
	to_scale->m[3][2] = 0.0f;
	to_scale->m[3][3] = 1.0;
}

t_mat4		create_mat4(float homogene)
{
	t_mat4		create_mat;

	create_mat.m[0][0] = 1.0f;
	create_mat.m[0][1] = 0.0f;
	create_mat.m[0][2] = 0.0f;
	create_mat.m[0][3] = 0.0f;
	create_mat.m[1][0] = 0.0f;
	create_mat.m[1][1] = 1.0f;
	create_mat.m[1][2] = 0.0f;
	create_mat.m[1][3] = 0.0f;
	create_mat.m[2][0] = 0.0f;
	create_mat.m[2][1] = 0.0f;
	create_mat.m[2][2] = 1.0f;
	create_mat.m[2][3] = 0.0f;
	create_mat.m[3][0] = 0.0f;
	create_mat.m[3][1] = 0.0f;
	create_mat.m[3][2] = 0.0f;
	create_mat.m[3][3] = homogene;
	return (create_mat);
}

t_mat4		make_translation(t_vec3 *src)
{
	t_mat4		new;

	new = create_mat4(1.0f);
	new.m[0][3] = src->x;
	new.m[1][3] = src->y;
	new.m[2][3] = src->z;
	return (new);
}

t_mat4		m4_x_m4(t_mat4 *a, t_mat4 *b)
{
	t_mat4		final_matrix;
	int			i;
	int			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			final_matrix.m[j][i] =
			a->m[j][0] * b->m[0][i] +
			a->m[j][1] * b->m[1][i] +
			a->m[j][2] * b->m[2][i] +
			a->m[j][3] * b->m[3][i];
			i++;
		}
		j++;
	}
	return (final_matrix);
}

t_mat4		matrix_scale(float value)
{
	t_mat4		scale;

	scale = create_mat4(1.0f);
	scale.m[0][0] = value;
	scale.m[1][1] = value;
	scale.m[2][2] = value;
	return (scale);
}

t_mat4		make_rot_x(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	to_rotate.m[1][2] = -sinf((degree * PI) / 180);
	to_rotate.m[2][1] = sinf((degree * PI) / 180);
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	return (to_rotate);
}

t_mat4		make_rot_y(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][2] = sinf((degree * PI) / 180);
	to_rotate.m[2][0] = -sinf((degree * PI) / 180);
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	return (to_rotate);
}

t_mat4		make_rot_z(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][1] = -sinf((degree * PI) / 180);
	to_rotate.m[1][0] = sinf((degree * PI) / 180);
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	return (to_rotate);
}

t_mat4		perspective(float fov, float aspect, float near, float far)
{
	t_mat4		perspected;
	float		half;

	half = tanf(((fov * PI) / 180) / 2.0f);
	perspected = create_mat4(0.0f);
	perspected.m[0][0] = 1.0f / (aspect * half);
	perspected.m[1][1] = 1.0f / (half);
	perspected.m[2][2] = -(far + near) / (far - near) * -1;
	perspected.m[2][3] = -1;
	perspected.m[3][2] = (2.0f * far * near) / (far - near) * -1;
	return (perspected);
}

t_mat4		look_at(t_vec3 r, t_vec3 u, t_vec3 d, t_vec3 p)
{
	t_mat4		mat_1;
	t_mat4		mat_2;
	t_mat4		look;
	mat_1 = create_mat4(1.0f);
	mat_1.m[0][0] = r.x;
	mat_1.m[0][1] = r.y;
	mat_1.m[0][2] = r.z;
	mat_1.m[1][0] = u.x;
	mat_1.m[1][1] = u.y;
	mat_1.m[1][2] = u.z;
	mat_1.m[2][0] = d.x;
	mat_1.m[2][1] = d.y;
	mat_1.m[2][2] = d.z;
	mat_2 = create_mat4(1.0f);
	mat_1.m[0][3] = -p.x;
	mat_1.m[1][3] = -p.y;
	mat_1.m[2][3] = -p.z;
	look = m4_x_m4(&mat_1, &mat_2);
	return (look);
}

float		magnitude(t_vec3 a)
{
	return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec3		normalize(t_vec3 a)
{
	t_vec3	normalized;
	float	magn;

	magn = magnitude(a);
	normalized.x = a.x / magn;
	normalized.y = a.y / magn;
	normalized.z = a.z / magn;
	return (normalized);
}

t_vec3		v_v_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.x * b.z - a.z * b.x;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

t_vec3		v_v_subs(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	return (r);
}

t_vec3		v_v_add(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	return (r);
}

t_vec3		v_v_mult(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = (a.y * b.z) - (a.z * b.y);
	r.y = (a.z * b.x) - (a.x * b.z);
	r.z = (a.x * b.y) - (a.y * b.x);
	return (r);
}

t_vec3		v_scal_mult(t_vec3 a, float v)
{
	t_vec3	r;

	r.x = a.x * v;
	r.y = a.y * v;
	r.z = a.z * v;
	return (r);
}