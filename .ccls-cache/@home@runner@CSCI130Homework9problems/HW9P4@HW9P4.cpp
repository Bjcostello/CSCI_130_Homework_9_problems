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
int CountUnhealthyCity(int matrix[][3], int N_ROWS, int city_col);

int MeanAirQualityIndex(int matrix[][3], int N_ROWS, int city_col);

int main() {

  int AirQuality_Index[10][3] = {{50, 68, 58},   {58, 115, 78},  {62, 110, 81},
                                 {66, 124, 110}, {64, 152, 121}, {46, 143, 90},
                                 {46, 143, 90},  {25, 91, 91},   {27, 19, 59},
                                 {17, 13, 27}};

  printMatrix_3col(AirQuality_Index, 10, 3);
  cout << endl;

  cout << "From 10/4/2020 to 10/13/2020 the air quality was unhealthy for "
          "sensitive groups in: "
       << endl;

  cout << "Grand Junction: " << CountUnhealthyCity(AirQuality_Index, 10, 0)
       << " times" << endl;
  cout << "Fort Collins: " << CountUnhealthyCity(AirQuality_Index, 10, 1)
       << " times" << endl;
  cout << "Denver - Boulder: " << CountUnhealthyCity(AirQuality_Index, 10, 2)
       << " times" << endl
       << endl;

  cout << "From 10/4/2020 to 10/13/2020 the air quality mean was: " << endl;

  cout << "Grand Junction: " << MeanAirQualityIndex(AirQuality_Index, 10, 0)
       << endl;
  cout << "Fort Collins: " << MeanAirQualityIndex(AirQuality_Index, 10, 1)
       << endl;
  cout << "Denver - Boulder: " << MeanAirQualityIndex(AirQuality_Index, 10, 2)
       << endl;
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

// function to do search through a column and return a count of values within a
// specific range
int CountUnhealthyCity(int matrix[][3], int N_ROWS, int city_col) {
  int row;
  int count = 0;
  for (row = 0; row < N_ROWS; row++) {
    if (matrix[row][city_col] >= 101) {
      count++;
    }
  }
  return count;
}

int MeanAirQualityIndex(int matrix[][3], int N_ROWS, int city_col) {
  int sum = 0;
  int row, avg;

  for (row = 0; row < N_ROWS; row++)
    sum = sum + matrix[row][city_col];
  avg = sum / N_ROWS;
  return avg;
}