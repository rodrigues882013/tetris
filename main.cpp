#include <stdio.h>
#include <stdlib.h>

#include "Game.h"
#include "Board.h"
#include "IO.h"
#include "Piece.h"


GLFWwindow *window;

//Window size
const GLint WIDTH = 800;
const GLint HEIGHT = 600;

void key_press_handle(GLFWwindow*, int, int, int, int);

Board *b;
Game *g;

int main()
{
	IO io;
	int screen_height = io.get_screen_height();

	//Pieces
	Piece piece;
	Board board (&piece, screen_height);
	Game game(&board, &piece, &io, screen_height);

	b = &board;
	g = &game;

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

	//Define handle to inputs
	glfwSetKeyCallback(window, key_press_handle);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	//Initializing glew
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
	{
		printf("Failed to initialise GLEW");
		return EXIT_FAILURE;
	}


	glViewport(0, 0, screenWidth, screenHeight); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glOrtho(0, screenWidth, 0, screenHeight, 0, 1); //set coordinate systems

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Draw openGL stuffs
		io.clear_screen();
		game.draw_scene();
		glfwSwapBuffers(window);

	}

	glfwTerminate();

	return EXIT_SUCCESS;


	
	

	return 0;
}

void key_press_handle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			glfwTerminate();
			break;

		case GLFW_KEY_RIGHT:
			if (b->is_possible_moviment(g->x_pos + 1, g->y_pos, g->p_piece, g->rotation))
				g->x_pos++;
			break;

		case GLFW_KEY_LEFT:
			break;

		case GLFW_KEY_DOWN:
			break;

		case GLFW_KEY_X:
			break;

		case GLFW_KEY_Y:
			break;
	}
}
