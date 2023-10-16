#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

// Constructor for ChessBoard class
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

// Number of rows in chess board
int ChessBoard::getNumRows()
{
    return numRows;
}

// Number of columns in chess board
int ChessBoard::getNumCols()
{
    return numCols;
}

// Creates a new chess piece 
void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    ChessPiece *piece = nullptr;
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
    board.at(startRow).at(startColumn) = piece;
}

// Moves a chess piece
bool ChessBoard::movePiece(int startRow, int startColumn, int endRow, int endColumn)
{
    ChessPiece *piece = board.at(startRow).at(startColumn);
    if (piece == nullptr)
    {
        return false;
    }
    return false;
}

// Displays the chess board
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
