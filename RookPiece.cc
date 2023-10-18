#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::RookPiece;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
    _type = Rook;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn) 
{
    if (getRow() == toRow) // Moving horizontally
    {
        int colStart = std::min(getColumn(), toColumn) + 1; 
        int colEnd = std::max(getColumn(), toColumn);

        for (int col = colStart; col < colEnd; col++) 
        {
            if (board.getPiece(toRow, col) != nullptr) // There's a piece in the path
                return false;
        }
    } 
    else if (getColumn() == toColumn) // Moving vertically
    {
        int rowStart = std::min(getRow(), toRow) + 1;
        int rowEnd = std::max(getRow(), toRow);

        for (int row = rowStart; row < rowEnd; row++) 
        {
            if (board.getPiece(row, toColumn) != nullptr) // There's a piece in the path
                return false;
        }
    } 
    else 
    {
        return false; // Neither moving in a row nor in a column
    }

    // Check if destination square is either empty or contains an opponent's piece
    ChessPiece *destinationPiece = board.getPiece(toRow, toColumn);
    if (destinationPiece == nullptr || destinationPiece->getColor() != getColor()) 
    {
        return true;
    }

    return false;
}

Type RookPiece::getType() {
    return _type;
}

const char *RookPiece::toString() {
    if (getColor() == White) {
        return "\u2656";
    }
    else {
        return "\u265C";
    }
}