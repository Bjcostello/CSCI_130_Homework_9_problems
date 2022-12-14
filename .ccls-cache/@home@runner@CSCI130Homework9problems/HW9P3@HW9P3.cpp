#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void print2DMatrix(double matrix[][6], int N_ROWS, int N_COLUMNS);
void zeroMatrix_6col(double matrix[][6], int N_ROWS, int N_COLUMNS);

int main() {

  double studentAnswer[6][6];
  int studentGrades[6];

  zeroMatrix_6col(studentAnswer, 6, 6);

  // inputs
  for (int i = 0; i < 6; i++)
    studentAnswer[i][0] = i + 1;

  for (int i = 0; i < 6; i++) {
    for (int a = 1; a < 6; a++) {
      cin >> studentAnswer[i][a];
    }
  }

  // calculate grades
  for (int i = 0; i < 6; i++) {
    int a = 0; // sum of all correct answers on test
    if (studentAnswer[i][1] == 1)
      a = a + 5;
    if (studentAnswer[i][2] == 1)
      a = a + 5;
    if (studentAnswer[i][3] == 0)
      a = a + 5;
    if (studentAnswer[i][4] == 0)
      a = a + 5;
    if (studentAnswer[i][5] == 1)
      a = a + 5;

    studentGrades[i] = a;
  }

  // outputs
  for (int i = 0; i < 5; i++) {
  }
  cout << endl << "Test answers: 1 1 0 0 1" << endl;
  cout << setw(7) << " tst #|";
  cout << setw(7) << "|";
  cout << setw(7) << "|";
  cout << setw(7) << "|";
  cout << setw(7) << "|";
  cout << setw(7) << "|" << endl;

  print2DMatrix(studentAnswer, 6, 6);

  cout << endl << "Grades in order from test 1-6: " << endl;
  for (int i = 0; i < 6; i++)
    cout << studentGrades[i] << endl;

  return 0;
}

// function to print the matrix in a matrix with 3 columns
void print2DMatrix(double matrix[][6], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

// fills a matrix with 0s
void zeroMatrix_6col(double matrix[][6], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++)
    for (col = 0; col < N_COLUMNS; col++)
      matrix[row][col] = 0;
}