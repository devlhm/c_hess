#include <stdio.h>
#include <ncurses.h>
#include "../include/piece.h"
#include "../include/rendering.h"

void populateBoard(struct Piece *board)
{
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        enum PieceColor color;
        enum PieceType type;

        if (y < 2)
            color = WHITE;
        else if (y > 5)
            color = BLACK;

        for (int x = 0; x < BOARD_SIZE; x++)
        {
            if (y == 1 || y == 6)
                type = PAWN;
            else if (y > 1 && y < 6)
                type = EMPTY;
            else
                switch (x)
                {
                case 0:
                    type = ROOK;
                    break;

                case 1:
                    type = KNIGHT;
                    break;

                case 2:
                    type = BISHOP;
                    break;

                case 3:
                    type = QUEEN;
                    break;

                case 4:
                    type = KING;
                    break;

                case 5:
                    type = BISHOP;
                    break;

                case 6:
                    type = KNIGHT;
                    break;

                case 7:
                    type = ROOK;
                    break;
                }

            struct Piece *piecePtr = (board + y * BOARD_SIZE) + x;
            (*piecePtr).type = type;
        }
    }
};

int main()
{
    struct Piece board[8][8];

    populateBoard(&board[0][0]);

    initscr();

    int lineLength = 30;
    drawGrid(2, (getmaxx(stdscr) - lineLength) / 2, lineLength);

    getch();
    endwin();
    return 0;
}
