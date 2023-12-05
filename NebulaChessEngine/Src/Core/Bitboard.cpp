#include "Bitboard.h"

#include <iostream>

namespace NCE {

	bool Bitboard::isOccupied(const int square) const {
		return (m_Bitboard >> square) & 1;
	}

	void Bitboard::Print() const {
		std::cout << "    ";
		for (int file = 0; file < 7; file++) std::cout << "__";
		std::cout << "_" << std::endl;
		for (int rank = 0; rank < 8; rank++) {
			std::cout << " " << rank + 1 << " |";
			for (int file = 0; file < 8; file++) {
				int square = 8 * rank + file;
				std::cout << ((m_Bitboard >> square) & 1) << " ";
			}
			std::cout << "\b|" << std::endl;
		}

		std::cout << "    ";
		for (int file = 0; file < 7; file++) std::cout << "--";
		std::cout << "-" << std::endl << "    ";
		for (int file = 0; file < 8; file++) std::cout << (char)('a' + file) << " ";
		std::cout << std::endl << std::endl;
	}
}