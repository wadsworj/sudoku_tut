#include "sudoku.h"

Box ** createBoxes()
{
    int x, y;
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);

    for (x = 0; x < 9; x++)
    {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9;

        for (y = 0; y < 9; y++)
            boxes[x]->possible[y] = 0;
    }

    return boxes;
}

int updateBoxes(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;
    Box * box;
    box = sudoku[row][column]->box;

    for (x = 0; x < 9; x++)
    {
        if (box->squares[x]->possible[number - 1] == 0)
        {
            box->squares[x]->solvable--;
            box->squares[x]->possible[number - 1] = 1;
        }
    }

}