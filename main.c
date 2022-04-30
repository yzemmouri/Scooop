#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

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
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
/* Fragment shader source code */
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main(void)
{
    GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

    /* Initialize the library */
    if (!glfwInit())
        exit(EXIT_FAILURE);

	/* Check openGL version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "scoop 1337", NULL, NULL);
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
        -0.5f, -0.5f, 0.0f, // left_down  
         0.5f, -0.5f, 0.0f, // right_down
         0.0f,  0.5f, 0.0f,  // top 
		 -0.5f/2, 0.0f, 0.0f, // middel_left
		 0.5f/2, 0.0f, 0.0f, // middel_right
		 0.0f, -0.5f, 0.0f // down_middel
		 
    }; 

	GLuint indices[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};
	/* create reference containers for the vertex array object and the vertex buffer object */
    GLuint VBO, VAO, EBO;
    /* generate the VAO and VBO with 1 object each */
	glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    /* Make the VAO the current vertex array object by binding it */
	glBindVertexArray(VAO);

	/* Buind the VBO specifying it's a GL_ARRAY_BUFFER */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	/* Introduce the vertices into the VBO */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* Configure the vertex attribute so that openGL knows how to read the VBO */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    /* Enable the vertex attribute so that openGL kwows to use it */
	glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// specify color of background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	// swap the back buffer witf the front buffer
	glfwSwapBuffers(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        /* Render here */

		// draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

	// optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}