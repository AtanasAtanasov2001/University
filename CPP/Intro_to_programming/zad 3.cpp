// zad 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int MAX_SIZE = 100;

int main()
{
    int row, col, W;
    
    int matrix[MAX_SIZE][MAX_SIZE];
    cin >> row >> col;
    cout << "Enter a number to multiply the matrix with: ";
    cin >> W;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            matrix[i][j] *= W ;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

 