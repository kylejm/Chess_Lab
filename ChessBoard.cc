#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol)
{
    numRows = numRow;
    numCols = numCol;
    board.resize(numRows);
    for (int row = 0; row < numRows; row++)
    {
        board.at(row).resize(numCols);
        for (int column = 0; column < numCols; column++)
        {
            board.at(row).at(column) = nullptr;
        }
    }
}

int ChessBoard::getNumRows()
{
    return numRows;
}

int ChessBoard::getNumCols()
{
    return numCols;
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    // Check if the position is valid
    if(startRow < 0 || startRow >= numRows || startColumn < 0 || startColumn >= numCols)
    {
        return;
    }

    // Remove any existing piece first
    ChessPiece* existingPiece = board.at(startRow).at(startColumn);
    delete existingPiece;
    board.at(startRow).at(startColumn) = nullptr;

    // Allocate memory and assign address for the new piece
    switch (ty)
    {
    case Pawn:
        board.at(startRow).at(startColumn) = new PawnPiece(*this, col, startRow, startColumn);
        break;
    case Rook:
        board.at(startRow).at(startColumn) = new RookPiece(*this, col, startRow, startColumn);
        break;
    case Bishop:
        board.at(startRow).at(startColumn) = new BishopPiece(*this, col, startRow, startColumn);
        break;
    case King:
        board.at(startRow).at(startColumn) = new KingPiece(*this, col, startRow, startColumn);
        break;
    default:
        break;
    }
}

bool ChessBoard::movePiece(int startRow, int startColumn, int endRow, int endColumn)
{
    return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    // Ensure that the starting and ending positions are within the board
    if (fromRow < 0 || fromColumn < 0 || toRow < 0 || toColumn < 0 || 
        fromRow >= numRows || fromColumn >= numCols || toRow >= numRows || toColumn >= numCols) {
        return false;
    }

    // Check if there is a piece at the starting position
    ChessPiece* piece = getPiece(fromRow, fromColumn);
    if (piece == nullptr) {
        return false;
    }

    // If there is a piece at the destination, check if it is the same color
    ChessPiece* destinationPiece = getPiece(toRow, toColumn);
    if (destinationPiece != nullptr && destinationPiece->getColor() == piece->getColor()) {
        return false;
    }

    // Check if the piece can move to the destination
    if (!piece->canMoveToLocation(toRow, toColumn)) {
        return false;
    }
    
    return true;
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
    return true;
}

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}