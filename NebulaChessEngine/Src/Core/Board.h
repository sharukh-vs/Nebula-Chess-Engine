#pragma once

#include <inttypes.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <bitset>

#include "Defines.h"
#include "Bitboard.h"

namespace NCE {

	class Board {

	public:
		Board()
			:m_pieces({ Bitboard::nthRank(2), Bitboard::PositionToBitBoard(a1, h1), Bitboard::PositionToBitBoard(b1, g1), Bitboard::PositionToBitBoard(c1, f1), 
						Bitboard::PositionToBitBoard(e1), Bitboard::PositionToBitBoard(d1), Bitboard::nthRank(7), Bitboard::PositionToBitBoard(a8, h8), 
						Bitboard::PositionToBitBoard(b8, g8), Bitboard::PositionToBitBoard(c8, f8), Bitboard::PositionToBitBoard(e8), 
						Bitboard::PositionToBitBoard(d8) })
		{
			m_pieces[WHITEKNIGHT].Print();
		}

		void Print() const;

	private:
		std::array<Bitboard, 12> m_pieces;
	};
}
