#pragma once

#include "Board.h"

namespace NCE {
	class Engine {
	public:
		void PrintBoard() const;
	private:
		Board m_Board;
	};
}