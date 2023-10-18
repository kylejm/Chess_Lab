#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::PawnPiece;

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
    _type = Pawn;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {  
    return false;  
}

Type PawnPiece::getType() {
    return _type;
}

const char *PawnPiece::toString() {
    if (getColor() == White) {
        return u8"\2659";
    }
    else {
        return u8"\265F";
    }
}