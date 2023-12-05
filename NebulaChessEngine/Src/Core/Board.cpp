#include "Board.h"

namespace NCE {

	void Board::Print() const {
		std::array<std::string, 8> chessboard;
		chessboard.fill("........");

		for (int rank = 0; rank < 8; rank++) {
			for (int file = 0; file < 8; file++) {
				int square = 8 * rank + file;
				for (int piece = 0; piece < NO_PIECES; piece++) {
					if (m_pieces[piece].isOccupied(square))
						chessboard[rank][file] = pieceToString((Pieces)piece);
				}
			}
			
		}

		std::cout << "    ";
		for (int file = 0; file < 7; file++) std::cout << "__";
		std::cout << "_" << std::endl;

		int rank = 0;

		for (auto square = chessboard.begin(); square != chessboard.end(); square++, rank++) {
			std::cout << " " << rank + 1 << " |";
			for (int i = 0; i < 8; i++)
				std::cout << (*square)[i] << " ";
			std::cout << "\b|" << std::endl;
		}

		std::cout << "    ";
		for (int file = 0; file < 7; file++) std::cout << "--";
		std::cout << "-" << std::endl << "    ";
		for (int file = 0; file < 8; file++) std::cout << (char)('a' + file) << " ";
		std::cout << std::endl << std::endl;
	}
}