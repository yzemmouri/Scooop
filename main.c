#include "scop.h"

static void error_callback(int error, const char* description)
{

    printf("Error_%d: %s\n", error, description);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
    glViewport(0, 0, width, height);
} 


int main(int ac, char **av)
{
	t_scopenv env;

	init_vertex_shader_source_code(&env);
	init_fragment_shader_source_code(&env);
	glfwSetErrorCallback(error_callback);

	//parcing model file
	
	init_parcing(&env);
	model_parcing(&env, ac, av);
	// int d = 0;
	// while (d < 12)
	// {
	// 	printf("%f ", env.vertices[d]);
	// 	d++;
	// }

    /* Initialize the library */
	// IMG_Init(IMG_INIT_PNG);
    if (!glfwInit())
        exit(EXIT_FAILURE);

	/* Check openGL version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);
	
    /* Create a windowed mode window and its OpenGL context */
    env.window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "scoop 1337", NULL, NULL);
    if (!env.window)
    {
        glfwTerminate();
       	exit(EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(env.window);
	glfwSetFramebufferSizeCallback(env.window, framebuffer_size_callback);
	// glfwSetCursorPosCallback(env.window, mouse_callback);
	/* Initialize Glad */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	    return -1;

	// configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

	// build and compile our shader program
	build_compile_shader(&env);
    // ------------------------------------
    // vertex shader

	// world space positions of our cubes
    // t_vec3 cubePositions[] = {
    //     (t_vec3){ 0.0f,  0.0f,  0.0f},
    //     (t_vec3){ 2.0f,  5.0f, -15.0f},
    //     (t_vec3){-1.5f, -2.2f, -2.5f},
    //     (t_vec3){-3.8f, -2.0f, -12.3f},
    //     (t_vec3){ 2.4f, -0.4f, -3.5f},
    //     (t_vec3){-1.7f,  3.0f, -7.5f},
    //     (t_vec3){ 1.3f, -2.0f, -2.5f},
    //     (t_vec3){ 1.5f,  2.0f, -2.5f},
    //     (t_vec3){ 1.5f,  0.2f, -1.5f},
    //     (t_vec3){-1.3f,  1.0f, -1.5f}
    // };

	generate_vao_vbo_ebo(&env);

    glUseProgram(env.shaderProgram);

	init_camera(&env);

	init_projection(&env);
    glUniformMatrix4fv(env.projection_loc, 1, GL_TRUE, &env.proj.m[0][0]);


	//hide the cursor and capture it 
	//glfwSetInputMode(env.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(env.window))
    {
		// glfwGetCursorPos(env.window, &env.xpos, &env.ypos);

		env.current_frame = (float)(glfwGetTime());
		env.delta_time = env.current_frame - env.last_frame;
		env.last_frame = env.current_frame;

		// mouse_callback(&env);
		processInput(&env);

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /* Render here */

		// draw our first triangle

		// update the uniform color
    	// float timeValue = glfwGetTime();
    	// float greenValue = sin(timeValue) / 2.0f + 0.5f;
    	// int vertexColorLocation = glGetUniformLocation(env.shaderProgram, "ourColor");
    	// glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		// bind Texture
        glBindTexture(GL_TEXTURE_2D, env.texture);
		
		//init camera
		

		env.look_at = create_mat4(1.0f);
		env.look_at = look_at(env.cam_right, env.cam_up, env.cam_dir, env.cam_pos);
		env.view_loc = glGetUniformLocation(env.shaderProgram, "view");
        glUniformMatrix4fv(env.view_loc, 1, GL_TRUE, &env.look_at.m[0][0]);

        // get matrix's uniform location and set matrix
		// env.model_loc = glGetUniformLocation(env.shaderProgram, "model");
        // glUniformMatrix4fv(env.model_loc, 1, GL_TRUE, &env.model.m[0][0]);
		// for (unsigned int i = 0; i < 1; i++)
        // {
            // calculate the model matrix for each object and pass it to shader before drawing
			env.model = create_mat4(1.0f);// make sure to initialize matrix to identity matrix first
			env.new_pos = (t_vec3){ 0.0f,  0.0f,  0.0f};
			env.trans = make_translation(&env.new_pos);
			env.model = m4_x_m4(&env.model, &env.trans);
			env.rotate_y = make_rot_y((float)glfwGetTime() * 20.0f);
			env.rotate_x = make_rot_x((float)glfwGetTime() * 20.0f);
			env.rotate_z = make_rot_z((float)glfwGetTime() * 20.0f);
			env.model = m4_x_m4(&env.model, &env.rotate_y);
			// env.model = m4_x_m4(&env.model, &env.rotate_x);
			env.model = m4_x_m4(&env.model, &env.rotate_z);
			env.model_loc = glGetUniformLocation(env.shaderProgram, "model");
        	glUniformMatrix4fv(env.model_loc, 1, GL_TRUE, &env.model.m[0][0]);

            // glDrawArrays(GL_TRIANGLES, 0, 36);
        // }
        glBindVertexArray(env.vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		glDrawElements(GL_TRIANGLES, env.num_indices * 3, GL_UNSIGNED_INT, 0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//render boxs
		// glDrawArrays(GL_TRIANGLES, 0, 36);

        /* Swap front and back buffers */
        glfwSwapBuffers(env.window);
        /* Poll for and process events */
        glfwPollEvents();
    }

	// optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &env.vao);
    glDeleteBuffers(1, &env.vbo);
	glDeleteBuffers(1, &env.ebo);
    glDeleteProgram(env.shaderProgram);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}