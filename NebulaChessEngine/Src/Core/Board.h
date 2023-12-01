#pragma once

#include <inttypes.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <bitset>

namespace NCE {

	enum Position {
		a1, b1, c1, d1, e1, f1, g1, h1,
		a2, b2, c2, d2, e2, f2, g2, h2,
		a3, b3, c3, d3, e3, f3, g3, h3,
		a4, b4, c4, d4, e4, f4, g4, h4,
		a5, b5, c5, d5, e5, f5, g5, h5,
		a6, b6, c6, d6, e6, f6, g6, h6,
		a7, b7, c7, d7, e7, f7, g7, h7,
		a8, b8, c8, d8, e8, f8, g8, h8,
	};

	enum Pieces {
		WHITEPAWN, WHITEROOK, WHITEBISHOP, WHITEKNIGHT, WHITEQUEEN, WHITEKING,
		BLACKPAWN, BLACKROOK, BLACKBISHOP, BLACKKNIGHT, BLACKQUEEN, BLACKKING, NO_PIECES,
	};

	class Board {

	public:
		Board()
			:m_pieces({ nthRank(2), PositionToBitBoard(a1, h1), PositionToBitBoard(b1, g1), PositionToBitBoard(c1, f1), 
						PositionToBitBoard(e1), PositionToBitBoard(d1), nthRank(7), PositionToBitBoard(a8, h8), 
						PositionToBitBoard(b8, g8), PositionToBitBoard(c8, f8), PositionToBitBoard(e8), PositionToBitBoard(d8) }),
			m_WhitePawn(nthRank(2)), 
			m_whiteRook(PositionToBitBoard(a1, h1)), m_WhiteKnight(PositionToBitBoard(b1, g1)), m_WhiteBishop(PositionToBitBoard(c1, f1)),
			m_WhiteQueen(PositionToBitBoard(e1)), m_WhiteKing(PositionToBitBoard(d1)),
			 m_BlackPawn(nthRank(7)), 
			m_BlackRook(PositionToBitBoard(a8, h8)), m_BlackKnight(PositionToBitBoard(b8, g8)), m_BlackBishop(PositionToBitBoard(c8, f8)),
			m_BlackQueen(PositionToBitBoard(e8)), m_BlackKing(PositionToBitBoard(d8))
		{ 
			/*std::bitset<64> x(m_pieces[WHITEPAWN]);
			std::cout << std::setw(64) << std::setfill('0') << x << std::endl;*/
			Print();
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
		std::array<uint64_t, 12> m_pieces;
		uint64_t m_WhitePawn;
		uint64_t m_whiteRook;
		uint64_t m_WhiteKnight;
		uint64_t m_WhiteBishop;
		uint64_t m_WhiteQueen;
		uint64_t m_WhiteKing;
		uint64_t m_BlackPawn;
		uint64_t m_BlackRook;
		uint64_t m_BlackKnight;
		uint64_t m_BlackBishop;
		uint64_t m_BlackQueen;
		uint64_t m_BlackKing;
	};
}