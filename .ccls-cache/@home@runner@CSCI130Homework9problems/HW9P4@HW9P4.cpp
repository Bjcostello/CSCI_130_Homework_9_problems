#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// functions
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS);
int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int N_COLUMNS,
                            int minVal, int maxVal);

int main() {

  int AirQuality_Index[10][3] = {{50, 68, 58},   {58, 115, 78},  {62, 110, 81},
                                 {66, 124, 110}, {64, 152, 121}, {46, 143, 90},
                                 {46, 143, 90},  {25, 91, 91},   {27, 19, 59},
                                 {17, 13, 27}};

  printMatrix_3col(AirQuality_Index, 10, 3);

  cout
      << "Number of days with air quality \'Unhelalthy for sensitive groups\': "
      << CountUnhealthySensitive(AirQuality_Index, 10, 3, 101, 150) << endl;
  return 0;
}

// function to print the matrix in a matrix with 3 columns
void printMatrix_3col(int matrix[][3], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

// function to find values in a matrix within specified range
int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int N_COLUMNS,
                            int minVal, int maxVal) {
  int row, col, count;
  count = 0;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++) {
      if ((matrix[row][col] >= minVal) and (matrix[row][col] <= maxVal)) {
        count++;
      }
    }
  }
  return count;
}