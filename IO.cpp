#include "IO.h"


IO::IO()
{
	
}

const char* IO::create_shaders(char flag)
{
	const char *shader = NULL;

	switch (flag)
	{
		case 'f':
			shader =
				"#version 330\n"
				"out vec4 frag_coulour;"
				"void main () {"
				"	frag_colour = vec4(1.0,  0.0,  0.0, 0.0);"
				"}";

			break;
		case 'v':
			shader =
				"#version 330\n"
				"in vec3 vp;"
				"void main () {"
				"	gl_Position = vec4 (vp, 1.0);"
				"}";

			break;
	}

	return shader;
}

void IO::calculate_coordinates(int x1, int y1, int x2, int y2, int* x3, int* y3, int* x4, int* y4)
{
	*x3 = x1;
	*y3 = y2;
	*y4 = y1;
	*x4 = x2;
}

void IO::draw_rectangle(int x1, int y1, int x2, int y2, color c)
{
	//Initializing variables
	GLuint vbo, vao = 0;
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint shader_programme = glCreateProgram();
	int x3, y3, y4, x4;

	calculate_coordinates(x1, y1, x2, y2, &x3, &y3, &x4, &y4);

	float points[] = {
		(float) x4, (float) y4,  0.0,
		(float) x1, (float) y1,  0.0,
		(float) x3, (float) y3,  0.0,
		(float) x2, (float) y2,  0.0
	};

	const char* vertex_shader = create_shaders('v');
	const char* fragment_shader = create_shaders('f');

	//Initializing VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), points, GL_STATIC_DRAW);

	//Initializing VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	/* -------- Initializing Shaders ------------*/
	//Vertex Shaders
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	//Fragment Shaders
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	//Combine shaders in single GPU program
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	//Drawing
	glUseProgram(shader_programme);
	glBindVertexArray(vao);

	// draw points 0-4 from the currently bound VAO with current in-use shader
	glDrawArrays(GL_QUADS, 0, 4);

}

void IO::clear_screen(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //clear background screen to black
}

int IO::get_screen_height(void)
{
	return HEIGHT;
}

int IO::init_graph(void)
{
	if (!glfwInit())
	{
		printf("Failed to start GLFW window");
		return EXIT_FAILURE;
	}


	window = glfwCreateWindow(WIDTH, HEIGHT, "Tetris", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window)
	{
		printf("Failed to create GLFW window");
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit())
	{
		printf("Failed to initialise GLEW");
		return EXIT_FAILURE;
	}

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"


	glViewport(0, 0, screenWidth, screenHeight); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glOrtho(0, screenWidth, 0, screenHeight, 0, 1); //set coordinate systems

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Draw openGL stuffs
		update_screen();
		
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}

int IO::poll_key(void)
{
	return 0;
}

int IO::get_key(void)
{
	return 0;
}

int IO::is_key_down(int key)
{
	return 0;
}

void IO::key_press_handle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			break;

		case GLFW_KEY_RIGHT:
			break;

		case GLFW_KEY_LEFT:
			break;

		case GLFW_KEY_DOWN:
			break;

		case GLFW_KEY_X:
			break;
	}
}

void IO::update_screen(void)
{
	glfwSwapBuffers(window);
}

void IO::set_board(Board *_board)
{
	*board = *_board;
}



