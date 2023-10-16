#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
    public:
        PawnPiece(ChessBoard &board, Color color, int row, int column);
        virtual ~PawnPiece() override;
        virtual Type getType() override;
        virtual bool canMoveToLocation(int toRow, int toColumn) override;
        virtual const char *toString() override;
    private:
        Type _type = Pawn;
    };
}

#endif
