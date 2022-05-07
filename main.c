#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "mathematics.h"

static void error_callback(int error, const char* description)
{
    printf("Error: %s\n", description);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

/* Vertex shader source code */
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
	"layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n"
	"layout (location = 2) in vec2 aTexCoord;\n"
	"out vec3 ourColor; // specify a color output to the fragment shader\n"
	"out vec2 TexCoord;\n"
	"uniform mat4 transform;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = transform * vec4(aPos, 1.0);\n"
	"	ourColor = aColor; // set the output variable to a dark-red color\n"
	"	TexCoord = aTexCoord;\n"
    "}\0";
/* Fragment shader source code */
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
	"in vec3 ourColor; // we set this variable in the OpenGL code.\n"
	"in vec2 TexCoord;\n"
	"uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "   FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);\n"
    "}\n\0";

int main(void)
{
    GLFWwindow* window;

	IMG_Init(IMG_INIT_PNG);

	glfwSetErrorCallback(error_callback);

    /* Initialize the library */
    if (!glfwInit())
        exit(EXIT_FAILURE);

	/* Check openGL version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 600, "scoop 1337", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
       	exit(EXIT_FAILURE);
    }

	glfwSetKeyCallback(window, key_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* Initialize Glad */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	    return -1;

	// build and compile our shader program
    // ------------------------------------
    // vertex shader
	/* Create vertex shader object and get reference */
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    /* Attach vertex shader source to the vertex shader object */
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    /* Compile vertex shader into machine code */
	glCompileShader(vertexShader);
   
    // fragment shader
	/* Create fragment shader object and get reference */
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    /* Attach fragment shader source to the fragment shader object */
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    /* Compile fragment shader into machine code */
	glCompileShader(fragmentShader);
    
	/* Create shader program object and get its reference */
    GLuint shaderProgram = glCreateProgram();
	/* Attach the vertex and fragment shaders to the shader program */
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // link all the shaders into the shader program
    glLinkProgram(shaderProgram);
   
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

	// set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    /* Vertices coordinates */
	GLfloat vertices[] = {
        // positions         // colors			//texture
    	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, // bottom right
    	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // bottom left
    	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.5f, 1.0f // top 
    }; 

	/* create reference containers for the vertex array object and the vertex buffer object */
    GLuint VBO, VAO;
    /* generate the VAO and VBO with 1 object each */
	glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    /* Make the VAO the current vertex array object by binding it */
	glBindVertexArray(VAO);

	/* Buind the VBO specifying it's a GL_ARRAY_BUFFER */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	/* Introduce the vertices into the VBO */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* Configure the vertex attribute so that openGL knows how to read the VBO */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    /* Enable the vertex attribute so that openGL kwows to use it */
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0); 
	
	// specify color of background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	// swap the back buffer witf the front buffer
	glfwSwapBuffers(window);

	GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
	SDL_Surface *img = IMG_Load("wall.jpg");
	
    if (img)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    	exit(EXIT_FAILURE);

    SDL_FreeSurface(img);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        /* Render here */

		// draw our first triangle
        glUseProgram(shaderProgram);

		// update the uniform color
    	// float timeValue = glfwGetTime();
    	// float greenValue = sin(timeValue) / 2.0f + 0.5f;
    	// int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    	// glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		// bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

		// create transformations
        t_mat4 transform = create_mat4(1.0f);// make sure to initialize matrix to identity matrix first
		t_vec3 new_pos = (t_vec3){0.5f, -0.5f, 0.0f};
		t_mat4 trans = make_translation(&new_pos);
		transform = m4_x_m4(&transform, &trans);
		t_mat4 rotate_z = create_mat4(1.0f);
		rotate_z = make_rot_z((float)glfwGetTime()*50);
		transform = m4_x_m4(&transform, &rotate_z);
        // get matrix's uniform location and set matrix
        unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_TRUE, &transform.m[0][0]);


        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

	// optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}