#include "../include/scop.h"

void	init_camera(t_scopenv *env)
{
	env->cam_pos = (t_vec3){0.0f, 0.0f, 3.0f};
	// env->cam_targ = (t_vec3){0.0f, 0.0f, 0.0f};
	// env->cam_dir = normalize(v_v_subs(env->cam_pos, env->cam_targ));
	env->up_vec = (t_vec3){0.0f, 1.0f, 0.0f};
	env->cam_dir = (t_vec3){0.0f, 0.0f, -1.0f};
	env->cam_right = normalize(v_v_cross(env->up_vec, env->cam_dir));
	env->cam_up = v_v_cross(env->cam_dir, env->cam_right);

	// timing
	env->delta_time = 0.0f;	// time between current frame and last frame
	env->last_frame = 0.0f;

}

void	init_projection(t_scopenv *env)
{
	env->fov = 45.0f;
	env->near = 1.0f;
	env->far = 100.0f;
	env->proj = perspective(env->fov, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, env->near, env->far);
	env->projection_loc = glGetUniformLocation(env->shaderProgram, "projection");
}

void	init_parcing(t_scopenv *env)
{
	env->nbr_lines = 0;
	env->fd = -1;
	env->rd_line = NULL;
	env->num_vertices = 0;
	env->num_indices = 0;
	env->num_lines = 0;
	env->v = 0;
	env->f = 0;
}

void	init_vertex_shader_source_code(t_scopenv *env)
{
	env->vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
	// "layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n"
	// "layout (location = 2) in vec2 aTexCoord;\n"
	// "out vec3 ourColor; // specify a color output to the fragment shader\n"
	// "out vec2 TexCoord;\n"
	"uniform mat4 model;\n"
	"uniform mat4 view;\n"
	"uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
	// "	ourColor = aColor; // set the output variable to a dark-red color\n"
	// "	TexCoord = aTexCoord;\n"
    "}\0";
}

void	init_fragment_shader_source_code(t_scopenv *env)
{
	env->fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
	// "in vec3 ourColor; // we set this variable in the OpenGL code.\n"
	// "in vec2 TexCoord;\n"
	// "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    // "   FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);\n"
	"   FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n\0";
}

// void	init_mouse(t_scopenv *env)
// {
// 	env->first_mouse = 1;
// 	env->yaw = -90.0f;
// 	env->pitch = 0.0f;
// 	env->last_x = 400.0f;
// 	env->last_y = 300.0f;
// }