#ifndef RENDERING_H
#define RENDERING_H

extern const int BOARD_SIZE;

extern const char ROW_LABELS[8];
extern const int COLUMN_LABELS[8];

void addGridLabels(int startX, int startY, int bottomY, int cellGap);

void drawGrid(int startY, int startX, int lineLength);

#endif // RENDERING_H