#include "ChessBoard.hh"
#include "KingPiece.hh"
#include "RookPiece.hh"
#include "KingPiece.hh"
#include "BishopPiece.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
    _type = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
    return false;    
}

Type KingPiece::getType() {
    return _type;
}

const char *KingPiece::toString() {
    if (getColor() == White) {
        return "\u2657";
    }
    else {
        return "\u265D";
    }
}