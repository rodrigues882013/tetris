#include "Game.h"

Game::Game(Board* board, Piece* piece, IO* io, int screen_height) : board(board), piece(piece), io(io), screen_height(screen_height) { }


int Game::get_rand(int p_a, int p_b)
{
	return rand() % (p_a - p_b + 1) + p_a;;
}

void Game::init_game(void)
{
}

void Game::draw_piece(int pX, int pY, int pPiece, int pRotation)
{
}

void Game::draw_board(void)
{
}


void Game::draw_scene(void)
{
}

void Game::create_new_piece(void)
{
}
