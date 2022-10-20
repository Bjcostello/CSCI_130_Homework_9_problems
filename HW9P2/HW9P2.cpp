#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void print2DMatrix(double matrix[][8], int N_ROWS, int N_COLUMNS);
void zeroMatrix_8col(double matrix[][8], int N_ROWS, int N_COLUMNS);

int main() {

  double studentGrades[60][8];

  zeroMatrix_8col(studentGrades, 60, 8);

  for (int i = 0; i < 60; i++)
    studentGrades[i][0] = i + 1;

  for (int i = 0; i < 5; i++) {
    for (int a = 1; a < 5; a++) {
      cin >> studentGrades[i][a];
    }
  }

  for (int i = 0; i < 60; i++) {
    studentGrades[i][5] = ((
      studentGrades[i][1] + 
      studentGrades[i][2] +
      studentGrades[i][3] + 
      studentGrades[i][4]) /
                           4);

    studentGrades[i][6] = (((double)studentGrades[i][1] * 0.2) +
                           ((double)studentGrades[i][2] * 0.3) +
                           ((double)studentGrades[i][3] * 0.3) +
                           ((double)studentGrades[i][4] * 0.2));

    //values to find lowest score
    int a = studentGrades[i][1];
    int b = studentGrades[i][2];
    int c = studentGrades[i][3];
    int d = studentGrades[i][4];
    if((a<=b)and(a<=c)and(a<=d))
      studentGrades[i][7] = b+c+d;
    else if((b<=a)and(b<=c)and(b<=d))
      studentGrades[i][7] = a+c+d;
    else if((c<=a)and(c<=b)and(c<=d))
      studentGrades[i][7] = a+b+d;
    else if((d<=a)and(d<=b)and(d<=c))
      studentGrades[i][7] = a+b+c;
    else{
    studentGrades[i][7] = -1;}
  }

  cout << setw(6) << " std #|"
       << " Grd 1|"
       << " Grd 2|"
       << " Grd 3|"
       << " Grd 4|"
       << " F avg|"
       << " F wgt|"
       << " F top3|" << endl;

  print2DMatrix(studentGrades, 60, 8);
  return 0;
}

// function to print the matrix in a matrix with 3 columns
void print2DMatrix(double matrix[][8], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < N_COLUMNS; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

// fills a matrix with 0s
void zeroMatrix_8col(double matrix[][8], int N_ROWS, int N_COLUMNS) {
  int row, col;
  for (row = 0; row < N_ROWS; row++)
    for (col = 0; col < N_COLUMNS; col++)
      matrix[row][col] = 0;
}