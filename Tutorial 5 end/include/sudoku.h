#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box
{
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solvable;
    struct Box * next;
} Box;

typedef struct Square
{
    int number;
    /* [1] [1] [1] [1] [0] [1] [1] [1] [1]
       [9] [8] [7] [6] [5] [4] [3] [2] [1] index*/
    int possible[9];
    int solvable;
    Box * box;
    int row;
    int column;
} Square;

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Square *** setUpPuzzle(int ** puzzle);

int updateSudoku(Square *** sudoku, int row, int column);
int checkPuzzle(Square *** sudoku);

int solveSquare(Square * square);

/* box functions */
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int column);


#endif