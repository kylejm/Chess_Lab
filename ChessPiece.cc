#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessPiece;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : board(board) {
    this->board = board;
    _color = color;
    _row = row;
    _column = column;
}

Color ChessPiece::getColor() {
    return _color;
}

Type ChessPiece::getType() {
    return Pawn;
}

int ChessPiece::getRow() {
    return _row;
}

int ChessPiece::getColumn() {
    return _column;
}

void ChessPiece::setPosition(int row, int column) {
    _row = row;
    _column = column;
}

bool ChessPiece::canMoveToLocation(int toRow, int toColumn) {
    return false;
}

const char *ChessPiece::toString() {
    return nullptr;
}

ChessPiece::~ChessPiece() {
    delete this;
}