/******************************************************************************
 CSCI 130: Matrix Example
*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void zeroMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS);
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS);

////////////////////// MAIN ///////////////////////////////////////
int main()
{
    const int N_ROWS = 4; 
    const int N_COLUMNS = 3;
    int MyMatrix[N_ROWS][N_COLUMNS] =  {{2, 3, 1},
                                        {15, 25, 13},
                                        {20, 4, 7},
                                        {11, 18, 14}};

    // display values in MyMatrix
    cout << "MyMatrix contains: " << endl;
    printMatrix_3col(MyMatrix, N_ROWS, N_COLUMNS);
    
    // zero this matrix and then display
    zeroMatrix_3col(MyMatrix, N_ROWS, N_COLUMNS);
    cout << "MyMatrix now contains: " << endl;
    printMatrix_3col(MyMatrix, N_ROWS, N_COLUMNS);
    
    return 0;
}

/////////////// USER-DEFINED MATRIX FUNCTIONS ////////////////////////////
// Recall: you can omit the size of the first dimension, but not the second

// function to zero each element in a matrix with 3 columns
void zeroMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS)
{
    int row, col;
    for (row = 0; row < N_ROWS; row++)
        for(col = 0; col < N_COLUMNS; col++)
            matrix[row][col] = 0;
}

// function to print the matrix in a matrix with 3 columns
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS)
{
    int row, col;
    for (row = 0; row < N_ROWS; row++)
    {
        for(col = 0; col < N_COLUMNS; col++)
            cout << setw(6) << matrix[row][col] << " ";
        
        cout << endl;    
    }
}


