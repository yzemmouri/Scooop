#ifndef SCOP_H
#define SCOP_H

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include "mathematics.h"
#include "../libft/libft.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

typedef struct	s_mouse
{
	float			pitch;
	float			yaw;
	double			xpos;
	double			ypos;
	float			last_x;
	float			last_y;
	float			x_offset;
	float			y_offset;
	int				first_mouse;
}				t_mouse;

typedef	struct	s_vertex
{
	t_vec3 position;
	t_vec3 normal;
	t_vec3 tex_coords;
}				t_vertex;

typedef struct	s_scopenv
{
	GLFWwindow*		window;
	const char		*vertexShaderSource;
	const char		*fragmentShaderSource;
	GLuint			vertexShader;
	GLuint			fragmentShader;
	GLuint			shaderProgram;
	GLuint			vbo;
	GLuint			vao;
	GLuint			ebo;
	GLuint			texture;
	SDL_Surface 	*img;
	t_vec3			cam_pos;
	t_vec3			cam_targ;
	t_vec3			cam_dir;
	t_vec3			up_vec;
	t_vec3			cam_right;
	t_vec3			cam_up;
	t_mat4			look_at;
	t_mat4			model;
	t_mat4			proj;
	t_vec3			new_pos;
	t_mat4			trans;
	t_mat4			rotate_x;
	t_mat4			rotate_y;
	t_mat4			rotate_z;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	unsigned int	model_loc;
	unsigned int	projection_loc;
	unsigned int	view_loc;
	float			fov;
	float			near;
	float			far;
	float			delta_time;
	float			last_frame;
	float			current_frame;
	GLfloat			*vertices;
	int				num_vertices;
	t_vec3			*indices;
	int				num_indices;
	int				fd;
	int				num_lines;
    char			*rd_line;
    int				nbr_lines;
	int				v;
	int				f;
}				t_scopenv;

void	model_parcing (t_scopenv *env, int ac, char **av);
void	init_camera(t_scopenv *env);
void	init_projection(t_scopenv *env);
void	init_parcing(t_scopenv *env);
void	init_vertex_shader_source_code(t_scopenv *env);
void	init_fragment_shader_source_code(t_scopenv *env);
void	processInput(t_scopenv *env);
void	build_compile_shader(t_scopenv *env);
void	generate_vao_vbo_ebo(t_scopenv *env);


#endif