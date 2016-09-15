#ifndef _PIECES_
#define _PIECES_
	
class Piece
{
	private:
		char* piece_name;

	public:
		int get_block_type(int, int, int, int);
		int get_intial_position_x(int, int);
		int get_initial_positiont_y(int, int);
};

#endif // _PIECES_