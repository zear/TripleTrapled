#ifndef _BOARD_H_
#define _BOARD_H_

#include "block.h"

#define BOARD_WIDTH	19 //29
#define BOARD_HEIGHT	15 //29
#define BLOCKS_MAX	50

#if defined(DEBUG)
#define BOARD_SPEED	1
#else
#define BOARD_SPEED	3
#endif

extern int board[BOARD_WIDTH][BOARD_HEIGHT];
extern int marker[BOARD_WIDTH][BOARD_HEIGHT];
extern int blockCounter;
extern int boardX;
extern int boardY;
extern int boardVx;
extern int boardVy;

void boardInit();
int boardInsertElement(int x, int y, Color color);
void boardClearAll();
void boardClearColor();
void boardCheckConnection();
void boardDraw();

#endif /* _BOARD_H_ */
