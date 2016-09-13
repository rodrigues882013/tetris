#ifndef _GAME_
#define _GAME_

// ------ Includes -----

#include "Board.h"
#include "Piece.h"
#include "IO.h"
#include <time.h>
#include <stdlib.h>
#include <SDL2\sdl.h>

// ------ Defines -----

#define WAIT_TIME 700           // Number of milliseconds that the piece remains before going 1 block down */ 



class Game
{
	private:

		int screen_height;             
		int next_x_pos;
		int next_y_pos;       
		int next_piece;
		int next_rotation;  
		Board* board;
		Piece* piece;
		IO* io;

		

	public:

		Game(Board*, Piece*, IO*, int);
		
		int get_rand(int, int);
		void init_game(void);
		void draw_piece(int, int, int, int);
		void draw_board(void);
		void draw_scene(void);
		void create_new_piece(void);

		int x_pos;
		int y_pos;               
		int p_piece;
		int rotation;          

	
};

#endif // _GAME_