#ifndef PIECE_H
#define PIECE_H

enum PieceType
{
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum PieceColor
{
    WHITE,
    BLACK
};

struct Piece
{
    enum PieceColor color;
    enum PieceType type;
};

#endif // PIECE_H