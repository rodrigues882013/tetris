#include "Game.h"

Game::Game(Board* board, Piece* piece, IO* io, int screen_height) : board(board), piece(piece), io(io), screen_height(screen_height) { }


int Game::get_rand(int p_a, int p_b)
{
	return rand() % (p_a - p_b + 1) + p_a;;
}

void Game::init_game(void)
{
	srand((unsigned int)time(NULL));

	//First Piece
	p_piece = get_rand(0, 6);
	rotation = get_rand(0, 3);
	x_pos = (BOARD_WIDTH / 2) + piece->get_intial_position_x(p_piece, rotation);
	y_pos = piece->get_initial_positiont_y(p_piece, rotation);

	//Next Piece
	next_piece = get_rand(0, 6);
	rotation = get_rand(0, 3);
	next_x_pos = BOARD_WIDTH + 5;
	next_y_pos = 5;

}

void Game::draw_piece(int p_x, int p_y, int p_piece, int rotation)
{
	color color;
	int pixel_x = board->get_x_pos_in_pixel(p_x);
	int pixel_y = board->get_y_pos_in_pixel(p_y);

	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			switch (piece->get_block_type(p_piece, rotation, j, i))
			{
				case 1: color = GREEN;
					break;
				case 2: color = BLUE;
					break;
			}

			if (piece->get_block_type(p_piece, rotation, j, i) != 0)
			{
				
				SDL_Rect rect;
				rect.x = pixel_x + i * BLOCK_SIZE;
				rect.y = pixel_y + j * BLOCK_SIZE;
				rect.w = pixel_x + i * BLOCK_SIZE;
				rect.h = (pixel_y + i * BLOCK_SIZE + BLOCK_SIZE - 1) - 1;

				/*io->draw_rectangle((pixel_x + i * BLOCK_SIZE),
					               (pixel_y + j * BLOCK_SIZE),
					               (pixel_x + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					               (pixel_y + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					               color);*/
				io->draw_rectangle(rect, color);
			}
		}
	}
}

void Game::draw_board(void)
{
	int x_1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int x_2 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int y = screen_height - (BLOCK_SIZE * BOARD_HEIGHT);

	io->draw_rectangle(x_1 - BOARD_LINE_WIDTH, y, x_1, screen_height - 1, BLUE);
	io->draw_rectangle(x_2, y, x_2 + BOARD_LINE_WIDTH, screen_height - 1, BLUE);

	x_1 += 1;

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			if (board->is_free_block(i, j))
			{
				SDL_Rect rect;
				rect.x = x_1 + i * BLOCK_SIZE;
				rect.y = y + j * BLOCK_SIZE;
				rect.w = (x_1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1;
				rect.h = ((y + j * BLOCK_SIZE) + BLOCK_SIZE - 1) - 1;

				/*io->draw_rectangle((x_1 + i * BLOCK_SIZE),
					(y + j * BLOCK_SIZE),
					(x_1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(y + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					RED);*/

				io->draw_rectangle(rect, RED);
			}
		}
	}
}


void Game::draw_scene(void)
{
	draw_board();
	draw_piece(x_pos, y_pos, p_piece, rotation);
	draw_piece(next_x_pos, next_y_pos, next_piece, next_rotation);

}

void Game::create_new_piece(void)
{
	//The new piece
	p_piece = next_piece;
	rotation = next_rotation;
	x_pos = (BOARD_WIDTH / 2) + piece->get_intial_position_x(p_piece, rotation);
	y_pos = piece->get_initial_positiont_y(p_piece, rotation);

	// Random next piece
	next_piece = get_rand(0, 6);
	next_rotation = get_rand(0, 3);
}

