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

		static inline uint64_t PositionToBitBoard(const int n) {
			return ((uint64_t)1 << n);
		}

		static inline uint64_t PositionToBitBoard(const int n1, const int n2) {
			return ((uint64_t)1 << n1) | ((uint64_t)1 << n2);
		}

		static inline uint64_t nthRank(const int n) {
			uint64_t firstRank = PositionToBitBoard(a1) | PositionToBitBoard(b1) | PositionToBitBoard(c1) | PositionToBitBoard(d1)
				| PositionToBitBoard(e1) | PositionToBitBoard(f1) | PositionToBitBoard(g1) | PositionToBitBoard(h1);
			return (firstRank << (8 * (n - 1)));
		}

		static inline uint64_t nthFile(const int n) {
			return PositionToBitBoard(a1 + (n - 1)) | PositionToBitBoard(a2 + (n - 1))
				| PositionToBitBoard(a3 + (n - 1)) | PositionToBitBoard(a4 + (n - 1))
				| PositionToBitBoard(a5 + (n - 1)) | PositionToBitBoard(a6 + (n - 1))
				| PositionToBitBoard(a7 + (n - 1)) | PositionToBitBoard(a8 + (n - 1));
		}

		void Print() const;

	private:
		std::array<Bitboard, 12> m_pieces;
	};
}
