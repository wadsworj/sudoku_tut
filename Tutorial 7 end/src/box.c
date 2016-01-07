#include "sudoku.h"

/*
 * int boxSingles(Square *** sudoku, Box ** boxes)
 *
 * Function to loop through all boxes and search
 * for a number within the box that only appears as
 * possible once.
 */
int boxSingles(Square *** sudoku, Box ** boxes)
{
    int i, j, x;
    int count;
    int temp;

    /* loop through boxes */
    for (i = 0; i < 9; i++)
    {
        /* loop through possible array */
        for (j = 0; j < 9; j++)
        {
            count = 0;

            /* loop through squares */
            for (x = 0; x < 9; x++)
            {
                if (boxes[i]->squares[x]->number != 0)
                    continue;

                if (boxes[i]->squares[x]->possible[j] == 0)
                {
                    count++;
                    temp = x;
                }

                if (count == 2)
                    break;
            }

            if (count == 1)
            {
                boxes[i]->squares[temp]->number = j + 1;
                UNSOLVED--;
                boxes[i]->squares[temp]->solvable = 0;

                updateSudoku(sudoku, boxes[i]->squares[temp]->row, boxes[i]->squares[temp]->column);

                return 1;
            }
        }
    }

    return 0;
}

/*
 * Box ** createBoxes()
 *
 * Function to create boxes while setting up
 * sudoku puzzle
 */
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

/*
 * int updateBoxes(Square *** sudoku, int row, int column)
 *
 * Once a square is solved within a box, all other
 * 
 */
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