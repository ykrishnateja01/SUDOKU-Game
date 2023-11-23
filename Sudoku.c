#include <stdio.h>
#include <stdlib.h>

void print(int arr[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int isSafe(int grid[][100], int row, int col, int num, int size)
{
    for (int x = 0; x < size; x++)
        if (grid[row][x] == num)
            return 0;
    for (int x = 0; x < size; x++)
        if (grid[x][col] == num)
            return 0;
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return 0;
    return 1;
}

int solveSudoku(int grid[][100], int row, int col, int size)
{
    if (row == size - 1 && col == size)
        return 1;
    if (col == size) 
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1, size);

    for (int num = 1; num <= size; num++) 
    {
        if (isSafe(grid, row, col, num, size)==1) 
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1, size)==1)
                return 1;
        }
        grid[row][col] = 0;
    }
    return 0;
}

int main()
{
    int size;
    printf("Enter the size of the Sudoku puzzle: ");
    scanf("%d", &size);
    int grid[100][100];
    printf("Enter the Sudoku puzzle:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &grid[i][j]);
    if (solveSudoku(grid, 0, 0, size)==1)
        print(grid, size);
    else
        printf("No solution exists");
    return 0;
}
