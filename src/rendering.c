#include "../include/rendering.h"
#include <ncurses.h>

const int BOARD_SIZE = 8;

const char ROW_LABELS[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
const int COLUMN_LABELS[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void addGridLabels(int startX, int startY, int bottomY, int cellGap)
{
    int labelMargin = 2;
    int rowLabelY = bottomY + labelMargin/2;
    int columnLabelX = startX - labelMargin;

    attron(A_BOLD);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        mvaddch(rowLabelY, (startX + i * cellGap * 2) + cellGap, ROW_LABELS[i]);
        mvprintw((startY + i * cellGap) + cellGap/2, startX - labelMargin, "%d", COLUMN_LABELS[i]);
    }
    
    attroff(A_BOLD);
}

void drawGrid(int startY, int startX, int lineLength)
{
    int gap = 2;

    int bottomY = startY + ((lineLength + gap) / 2);
    int endX = startX + lineLength + gap;

    for (int y = 0; y <= BOARD_SIZE; y++)
    {
        mvhline(startY + y * gap, startX, 0, lineLength + gap);
    }

    for (int x = 0; x <= BOARD_SIZE; x++)
    {
        int xPos = startX + x * gap * 2;
        mvvline(startY, xPos, 0, (lineLength / 2) + gap);
        if (x > 0 && x < BOARD_SIZE)
        {
            mvaddch(startY, xPos, ACS_TTEE);
            mvaddch(bottomY, xPos, ACS_BTEE);
        };
    }

    mvaddch(startY, startX, ACS_ULCORNER);
    mvaddch(startY, endX, ACS_URCORNER);
    mvaddch(bottomY, startX, ACS_LLCORNER);
    mvaddch(bottomY, endX, ACS_LRCORNER);

    addGridLabels(startX, startY, bottomY, gap);

    refresh();
}