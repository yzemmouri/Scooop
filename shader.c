#include "scop.h"

// set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    /* Vertices coordinates */

	// GLfloat vertices[] = {
    //     // positions         // colors			//texture
    // 	-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, // bottom right
    // 	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // bottom left
    // 	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f, // top 
	// 	 0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
 	// 	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
 	// 	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
	// 	-0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
    // 	 0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
    // 	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
	// 	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
 	// 	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
 	// 	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
	// 	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
    // 	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
    // 	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
	// 	-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
 	// 	-0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
 	// 	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
	// 	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
    // 	 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
    // 	 0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
	// 	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
 	// 	 0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
 	// 	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
	// 	-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
    // 	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
    // 	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
	// 	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
 	// 	-0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
 	// 	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
	// 	-0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
    // 	 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
    // 	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
	// 	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
 	// 	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
 	// 	-0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
    // }; 

// GLfloat vertices[] = {
// 	-0.5f, -0.5f, -0.5f,
// 	 0.5f, -0.5f, -0.5f,
// 	 0.5f, 	0.5f, -0.5f,
// 	-0.5f, 	0.5f, -0.5f,
// };

// t_vec3 vertices[] = {
// 	(t_vec3){-0.5f, -0.5f, -0.5f},
// 	(t_vec3){ 0.5f, -0.5f, -0.5f},
// 	(t_vec3){ 0.5f, 	0.5f, -0.5f},
// 	(t_vec3){-0.5f, 	0.5f, -0.5f},
// 	//  0.75f, 0.0f, -0.5f
// };

// GLuint indices[] = {
// 	0, 1, 3,
// 	1, 2, 3
// 	// 1, 4, 2, 3
// };

void	build_compile_shader(t_scopenv *env)
{
	/* Create vertex shader object and get reference */
    env->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    /* Attach vertex shader source to the vertex shader object */
	glShaderSource(env->vertexShader, 1, &env->vertexShaderSource, NULL);
    /* Compile vertex shader into machine code */
	glCompileShader(env->vertexShader);
   
    // fragment shader
	/* Create fragment shader object and get reference */
    env->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    /* Attach fragment shader source to the fragment shader object */
	glShaderSource(env->fragmentShader, 1, &env->fragmentShaderSource, NULL);
    /* Compile fragment shader into machine code */
	glCompileShader(env->fragmentShader);
    
	/* Create shader program object and get its reference */
    env->shaderProgram = glCreateProgram();
	/* Attach the vertex and fragment shaders to the shader program */
    glAttachShader(env->shaderProgram, env->vertexShader);
    glAttachShader(env->shaderProgram, env->fragmentShader);
    // link all the shaders into the shader program
    glLinkProgram(env->shaderProgram);
   
    glDeleteShader(env->vertexShader);
    glDeleteShader(env->fragmentShader);
}

// void	generate_vao_vbo_ebo(t_scopenv *env)
// {
// 	/* generate the VAO and VBO with 1 object each */
// 	glGenVertexArrays(1, &env->vao);
//     glGenBuffers(1, &env->vbo);
//     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//     /* Make the VAO the current vertex array object by binding it */
// 	glBindVertexArray(env->vao);

// 	/* Buind the VBO specifying it's a GL_ARRAY_BUFFER */
//     glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
// 	/* Introduce the vertices into the VBO */
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

// 	/* Configure the vertex attribute so that openGL knows how to read the VBO */
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//     /* Enable the vertex attribute so that openGL kwows to use it */
// 	glEnableVertexAttribArray(0);

// 	// color attribute
// 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
// 	glEnableVertexAttribArray(1);

// 	// texture coord attribute
//     glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//     glEnableVertexAttribArray(2);

//     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//     // glBindBuffer(GL_ARRAY_BUFFER, 0); 

//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     // glBindVertexArray(0); 
	
// 	// specify color of background
// 	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//     glClear(GL_COLOR_BUFFER_BIT);
// 	// swap the back buffer witf the front buffer
// 	glfwSwapBuffers(env->window);

//     glGenTextures(1, &env->texture);
//     glBindTexture(GL_TEXTURE_2D, env->texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//     // set the texture wrapping parameters
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     // set texture filtering parameters
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// 	// load image, create texture and generate mipmaps
// 	env->img = IMG_Load("wall.jpg");
	
//     if (env->img)
//     {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->img->w, env->img->h, 0, GL_RGB, GL_UNSIGNED_BYTE, env->img->pixels);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     }
//     else
//     	exit(EXIT_FAILURE);

//     SDL_FreeSurface(env->img);
// }

void	generate_vao_vbo_ebo(t_scopenv *env)
{
	/* generate the VAO and VBO with 1 object each */
	glGenVertexArrays(1, &env->vao);
    glGenBuffers(1, &env->vbo);
	glGenBuffers(1, &env->ebo);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    /* Make the VAO the current vertex array object by binding it */
	glBindVertexArray(env->vao);

	/* Buind the VBO specifying it's a GL_ARRAY_BUFFER */
    glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	/* Introduce the vertices into the VBO */
    glBufferData(GL_ARRAY_BUFFER, sizeof(env->vertices) * env->num_vertices * 3, env->vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(env->indices) * env->num_indices * 3, env->indices, GL_STATIC_DRAW);
	/* Configure the vertex attribute so that openGL knows how to read the VBO */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    /* Enable the vertex attribute so that openGL kwows to use it */
	glEnableVertexAttribArray(0);

	// // color attribute
	// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
	// glEnableVertexAttribArray(1);

	// // texture coord attribute
    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    // glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// specify color of background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	// swap the back buffer with the front buffer
	glfwSwapBuffers(env->window);

    // glGenTextures(1, &env->texture);
    // glBindTexture(GL_TEXTURE_2D, env->texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // // set the texture wrapping parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// // load image, create texture and generate mipmaps
	// env->img = IMG_Load("wall.jpg");
	
    // if (env->img)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->img->w, env->img->h, 0, GL_RGB, GL_UNSIGNED_BYTE, env->img->pixels);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // 	exit(EXIT_FAILURE);

    // SDL_FreeSurface(env->img);
}