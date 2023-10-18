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
    int direction = (getColor() == White) ? 1 : -1; // Pawns move up for White and down for Black
    int startRow = (getColor() == White) ? 1 : 6;  // Starting row for White is 1 and for Black is 6 (0-based index)

    // Normal move forward (not capturing)
    if (toColumn == getColumn()) {
        // Move one step forward
        if (toRow == getRow() + direction && board.getPiece(toRow, toColumn) == nullptr) {
            return true;
        }
        // Move two steps forward from starting position
        else if (getRow() == startRow && toRow == getRow() + (2 * direction) && board.getPiece(toRow, toColumn) == nullptr && board.getPiece(getRow() + direction, toColumn) == nullptr) {
            return true;
        }
    }
    // Capturing move
    else if (abs(toColumn - getColumn()) == 1 && toRow == getRow() + direction) {
        ChessPiece *destinationPiece = board.getPiece(toRow, toColumn);
        if (destinationPiece != nullptr && destinationPiece->getColor() != getColor()) {
            return true;
        }
    }

    return false;
}

Type PawnPiece::getType() {
    return _type;
}

const char *PawnPiece::toString() {
    if (getColor() == White) {
        return "\u2659";
    }
    else {
        return "\u265F";
    }
}