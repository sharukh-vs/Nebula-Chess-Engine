#pragma once

#include "Defines.h"

#include <cinttypes>

namespace NCE {
	class Bitboard {

	public:

		Bitboard() :m_Bitboard(0) {}
		Bitboard(uint64_t bitboard) :m_Bitboard(bitboard) {}

		void setBitboard(uint64_t bitboard)
		{
			m_Bitboard = bitboard;
		}

		void Print() const;

		static uint64_t PositionToBitBoard(const int n) {
			return ((uint64_t)1 << n);
		}

		static uint64_t PositionToBitBoard(const int n1, const int n2) {
			return ((uint64_t)1 << n1) | ((uint64_t)1 << n2);
		}
		static uint64_t nthRank(int n) {
			uint64_t firstRank = PositionToBitBoard(a1) | PositionToBitBoard(b1) | PositionToBitBoard(c1) | PositionToBitBoard(d1)
				| PositionToBitBoard(e1) | PositionToBitBoard(f1) | PositionToBitBoard(g1) | PositionToBitBoard(h1);
			// Bitboard b(firstRank << (8 * (n - 1)));
			return (firstRank >> (8 * (n - 1)));
		}

		static uint64_t Bitboard::nthFile(const int n) {
			uint64_t firstFile = PositionToBitBoard(a1 + (n - 1)) | PositionToBitBoard(a2 + (n - 1))
				| PositionToBitBoard(a3 + (n - 1)) | PositionToBitBoard(a4 + (n - 1))
				| PositionToBitBoard(a5 + (n - 1)) | PositionToBitBoard(a6 + (n - 1))
				| PositionToBitBoard(a7 + (n - 1)) | PositionToBitBoard(a8 + (n - 1));
			return firstFile;
		}

		bool isOccupied(const int square) const;

	private:
		uint64_t m_Bitboard;
	};
}