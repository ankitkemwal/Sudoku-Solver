#include <iostream>
#include <cmath>
using namespace std;

//safety function
bool isSafeToPlace(int board[][9], int i, int j, int n, int num)
{
    // Check row and column for the same number
    for (int k = 0; k < n; k++)
    {
        if (board[i][k] == num || board[k][j] == num)
        {
            return false;
        }
    }

    // check a small grid for the same number
    n = sqrt(n);
    int si = (i / n) * n;
    int sj = (j / n) * n;

    for (int i = si; i < si + n; i++)
    {
        for (int j = sj; j < sj + n; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}
//solver function
bool SudokuSolver(int board[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // Print the sudoku
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // recursive case
    if (j == n)
    {
        return SudokuSolver(board, i + 1, 0, n);
    }
    // If the cell is already filled, move to the next cell
    if (board[i][j] != 0)
    {
        return SudokuSolver(board, i, j + 1, n);
    }
    // Fill one empty cell, recurs over the rest
    for (int num = 1; num <= n; num++)
    {
        if (isSafeToPlace(board, i, j, n, num) == true)
        {
            // Place the number if its safe to put it
            board[i][j] = num;
            bool restSolved = SudokuSolver(board, i, j + 1, n);
            if (restSolved == true)
            {
                return true;
            }
            board[i][j] = 0; // backtracking to empty if number placed is not safe
        }
    }
    return false;
}

int main()
{
// inputting the 9x9 matrix
    cout<<"Enter your problem sudoku matrix: "<<endl;
    int mat[9][9] ;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
        cin>>mat[i][j];
    }
    cout<<endl;
// calling the solver function
    cout<<"The solved sudoku is: "<<endl;
    SudokuSolver(mat, 0, 0, 9);

    return 0;
}
