#ifndef _IO_
#define _IO_


//General Includes
#include <stdlib.h>
#include <stdio.h>
#include "Board.h"

//GLEW
#define GLEW_STATIC 
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>


enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX }; // Colors

class IO
{
	private:
		//Window definition
		GLFWwindow *window;

		//Window size
		const GLint WIDTH = 800;
		const GLint HEIGHT = 600;
		Board *board;

	public:
		IO(void);
		void draw_rectangle(int, int, int, int, enum color);
		void clear_screen(void);
		int get_screen_height(void);
		int init_graph(void);
		int poll_key(void);
		int get_key(void);
		int is_key_down(int);
		void update_screen(void);
		void calculate_coordinates(int, int, int, int, int*, int*, int*, int*);
		const char* create_shaders(char);
		void key_press_handle(GLFWwindow*, int, int, int, int);
		void set_board(Board*);
};

#endif
