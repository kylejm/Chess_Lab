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
    int rowDifference = abs(toRow - getRow());
    int colDifference = abs(toColumn - getColumn());

    // Check if movement is diagonal
    if (rowDifference != colDifference) {
        return false;
    }

    // Calculate the direction of movement
    int rowDirection = (toRow > getRow()) ? 1 : -1;
    int colDirection = (toColumn > getColumn()) ? 1 : -1;

    // Check the path for other pieces
    int currentRow = getRow() + rowDirection;
    int currentCol = getColumn() + colDirection;
    while (currentRow != toRow && currentCol != toColumn) {
        if (board.getPiece(currentRow, currentCol) != nullptr) {
            return false; // A piece is blocking the path
        }
        currentRow += rowDirection;
        currentCol += colDirection;
    }

    // Destination should be either empty or occupied by an opponent's piece
    ChessPiece *destinationPiece = board.getPiece(toRow, toColumn);
    if (destinationPiece != nullptr && destinationPiece->getColor() == getColor()) {
        return false; // Can't capture own piece
    }

    return true;
}

Type BishopPiece::getType() {
    return _type;
}

const char *BishopPiece::toString() {
    if (getColor() == White) {
        return "\u2657";
    }
    else {
        return "\u265D";
    }
}