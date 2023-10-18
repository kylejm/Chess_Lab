#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::RookPiece;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
    _type = Rook;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {  
    return false;  
}

Type RookPiece::getType() {
    return _type;
}

const char *RookPiece::toString() {
    if (getColor() == White) {
        return u8"\2656";
    }
    else {
        return u8"\265C";
    }
}