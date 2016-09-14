#include "IO.h"

//static Uint32 colors[COLOR_MAX] = { 0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
//0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff };

//Window definition
static GLFWwindow *window;

//Window size
const GLint WIDTH = 800;
const GLint HEIGHT = 600;



IO::IO(void)
{
	
}

void IO::draw_rectangle(int x_1, int y_1, int x_2, int y_2, color c)
{
	glBegin(GL_LINES);
		//glColor3fv();
		int w = x_2 - x_1;
		int h = y_2 - y_1;
		glVertex4i(x_1, y_1, w, h);
	glEnd();

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
	glfwInit();

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

	glViewport(0, 0, screenWidth, screenHeight);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Draw openGL stuffs
		glfwSwapBuffers(window);

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

void IO::update_screen(void)
{
	glfwSwapBuffers(window);
}


