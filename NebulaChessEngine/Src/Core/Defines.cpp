#include "Defines.h"

namespace NCE {
	const char pieceToString(const Pieces piece) {
		switch (piece) {
		case WHITEPAWN: return 'P';
			break;
		case WHITEROOK: return 'R';
			break;
		case WHITEBISHOP: return 'B';
			break;
		case WHITEKNIGHT: return 'N';
			break;
		case WHITEQUEEN: return 'Q';
			break;
		case WHITEKING: return 'K';
			break;
		case BLACKPAWN: return 'p';
			break;
		case BLACKROOK: return 'r';
			break;
		case BLACKBISHOP: return 'b';
			break;
		case BLACKKNIGHT: return 'n';
			break;
		case BLACKQUEEN: return 'q';
			break;
		case BLACKKING: return 'k';
			break;
		default: return 'E';
			break;
		}
	}
}