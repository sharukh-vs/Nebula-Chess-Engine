#include "Board.h"

namespace NCE {
	void Board::Print() const {
		std::array<std::string, 8> chessBoard;
		chessBoard.fill("........");

		for (int rank = 0; rank < 8; rank++)
		{
			for (int file = 0; file < 8; file++)
			{
				int squareIndex = 8 * rank + file;
				if ((m_WhitePawn >> squareIndex) & 1 || (m_BlackPawn >> squareIndex) & 1)
					chessBoard[rank][file] = 'P';
				else if ((m_whiteRook >> squareIndex) & 1 || (m_BlackRook >> squareIndex) & 1)
					chessBoard[rank][file] = 'R';
				else if ((m_WhiteKnight >> squareIndex) & 1 || (m_BlackKnight >> squareIndex) & 1)
					chessBoard[rank][file] = 'N';
				else if ((m_WhiteBishop >> squareIndex) & 1 || (m_BlackBishop >> squareIndex) & 1)
					chessBoard[rank][file] = 'B';
				else if ((m_WhiteQueen >> squareIndex) & 1 || (m_BlackQueen >> squareIndex) & 1)
					chessBoard[rank][file] = 'Q';
				else if ((m_WhiteKing >> squareIndex) & 1 || (m_BlackKing >> squareIndex) & 1)
					chessBoard[rank][file] = 'K';

			}
		}

		for (auto square = chessBoard.rbegin(); square != chessBoard.rend(); square++) {
			for (int i = 0; i < 8; i++)
				std::cout << (*square)[i] << " ";
			std::cout << std::endl;
		}

	}
}