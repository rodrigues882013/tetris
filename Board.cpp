#include "Board.h"

void Board::init_board(void)
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			board[i][j] = POS_FREE;
		}
	}
}

void Board::delete_line(int y)
{
	for (int j = y; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			board[i][j] = board[i][j - 1];
		}
	}
}

Board::Board(Piece* piece, int screen_height) : piece(piece), screen_height(screen_height){ }

int Board::get_x_pos_in_pixel(int pos)
{
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2 ))) + (pos * BLOCK_SIZE));
}

int Board::get_y_pos_in_pixel(int pos)
{
	return ((screen_height - (BLOCK_SIZE * BOARD_HEIGHT)) + (pos * BLOCK_SIZE));
}

bool Board::is_free_block(int x, int y)
{
	return board[x][y] == POS_FREE;
}

bool Board::is_possible_moviment(int x, int y, int p_piece, int rotation)
{
	for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
		{
			if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT)
			{
				if (piece->get_block_type(p_piece, rotation, j2, j1) != 0)
				{
					return false;
				}
			}

			if (j1 >= 0)
			{
				if ((piece->get_block_type(p_piece, rotation, j2, j1) != 0) && (!is_free_block(i1, j1)))
				{
					return false;
				}
			}
		}
	}
	
	return true; //No colisions
}

void Board::store_piece(int x, int y, int piece_to_draw, int  rotation)
{
	for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
		{
			if (piece->get_block_type(piece_to_draw, rotation, j2, i2) != 0)
			{
				board[i1][j1] = POS_FILLED;
			}
		}
	}
}

void Board::delete_possible_lines(void)
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (board[i][j] != POS_FILLED) break;
			i++;
		}

		if (i == BOARD_WIDTH) delete_line(j);
	}
}

bool Board::is_game_over(void)
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (board[i][0] == POS_FILLED)
		{
			return true;
		}
	}
}
