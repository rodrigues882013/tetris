#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

// ------ Defines -----

#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16               // Width and Height of each block of a piece
#define BOARD_POSITION 320          // Center position of the board from the left of the screen
#define BOARD_WIDTH 10              // Board width in blocks 
#define BOARD_HEIGHT 20             // Board height in blocks
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit      
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5              // Number of horizontal and vertical blocks of a matrix piece


class Board
{
	private:
		enum { POS_FREE, POS_FILLED}; // POS_FREE = free position of the board; POS_FILLED = filled position of the board
		int board[BOARD_WIDTH][BOARD_HEIGHT];
		Piece *piece;
		int screen_height;
		void init_board(void);
		void delete_line(int);

	public:
		Board(Piece*, int);
		int get_x_pos_in_pixel(int);
		int get_y_pos_in_pixel(int);
		bool is_free_block(int, int);
		bool is_possible_moviment(int, int, int, int);
		void store_piece(int, int, int, int);
		void delete_possible_lines(void);
		bool is_game_over(void);


};

#endif