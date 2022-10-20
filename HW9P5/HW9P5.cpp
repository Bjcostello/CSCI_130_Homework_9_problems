#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// Functions
void printMatrix(int matrix[][2], int N_ROWS, int N_COLUMNS);

int main() {

  int Matrix[2][2];
  int Adjoint[2][2];
  double Inverse[2][2];

  int a, b, c, d;
  int determinant;

  for (int i = 0; i < 2; i++)
    for (int a = 0; a < 2; a++)
      cin >> Matrix[i][a];

  a = Matrix[0][0];
  b = Matrix[0][1];
  c = Matrix[1][0];
  d = Matrix[1][1];

  determinant = ((a * d) - (b * c));

  cout << a << b << c << d << endl;

  cout << "initial Matrix: " << endl;
  printMatrix(Matrix, 2, 2);

  if (determinant == 0) {
    cout << "This Matrix has no inverse" << endl;
    return 0;
  }

  // Adjoint matrix
  cout << endl;

  Adjoint[0][0] = Matrix[1][1];
  Adjoint[0][1] = Matrix[0][1] * -1;
  Adjoint[1][0] = Matrix[1][0] * -1;
  Adjoint[1][1] = Matrix[0][0];

  cout << "Adjoint Matrix: " << endl;
  printMatrix(Adjoint, 2, 2);

  //calculate inverse
  cout << endl << "Inverse Matrix: " << endl;
  
  Adjoint[0][0] = Matrix[1][1];
  Adjoint[0][1] = Matrix[0][1] * -1;
  Adjoint[1][0] = Matrix[1][0] * -1;
  Adjoint[1][1] = Matrix[0][0];

  
  return 0;
}

// function to print the matrix in a matrix with 2 columns
void printMatrix(int matrix[][2], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++)
      cout << setw(3) << matrix[row][col] << " ";

    cout << endl;
  }
}