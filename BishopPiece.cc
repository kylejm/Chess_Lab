#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::BishopPiece;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
    _type = Bishop;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) { 
    return false;   
}

Type BishopPiece::getType() {
    return _type;
}

const char *BishopPiece::toString() {
    if (getColor() == White) {
        return u8"\2657";
    }
    else {
        return u8"\265D";
    }
}