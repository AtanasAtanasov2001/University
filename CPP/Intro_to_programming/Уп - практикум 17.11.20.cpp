// Уп - практикум 17.11.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
const int MAX_SIZE = 100;
int main()
{
    //for every task
    /*int row, col;
    int matrix[MAX_SIZE][MAX_SIZE];
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }*/

    // 

    //task 1
           /* for (int i = 0; i < row; i++)
           {
               for (int j = 0; j < col; j++)
           {

               matrix[i][j] += 10;
               cout << matrix[i][j] << " ";
           }
        cout << endl;
      }*/

      // task 2
     /*int min = INT_MAX;
     int max = INT_MIN;
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < col; j++)
          {
               if (max < matrix[i][j])
               {
                   max = matrix[i][j];
                   continue;
               }
               if (min > matrix[i][j])
               {
                   min = matrix[i][j];
               }
          }
     }
     cout << "maximalen element: " << max << endl;
     cout << "minimalen element: " << min << endl;*/

     //task 3
     /* sum of row
     int sum = 0;
     for (int i = 0; i < row; i++)
     {
         sum = 0;
         for (int j = 0; j < col; j++)
     {
         sum += matrix[i][j];
     }
     cout<<"Sum of row " << i << "is "<< sum << endl;
     }*/

//sum of col
     /*int sum = 0;
     for (int i = 0; i < col; i++)
     {
        sum = 0;
        for (int j = 0; j < row; j++)
     {
        sum += matrix[j][i];
     }
     cout << "Sum of col " << i << "is " << sum << endl;
    }*/

    /*
 //sum of the main diagonal
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
         sum += matrix[i][i];
    }
    cout << "the sum of the main diagonal is " << sum << endl;*/

 // sum of second diagonal

    /*int sum = 0;
    for (int i = 0; i < row; i++)
    {
        cout << i << " " << row - i - 1 << endl;
        sum += matrix[i][row - i - 1];
    }
    cout << "sum of second diagonal is: " << sum << endl;*/

    // task 4
    /*int x;
    cin >> x;
    bool isfound =false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == x)
            {
                matrix[i][j] *= 10;
                cout << matrix[i][j] << endl;
                cout << i * col + j << endl;
                isfound = true;
            }
        }
    }
    if (!isfound)
    {
        cout << "404 not found" << endl;
    }*/

    //task 5
    //char sentence[MAX_SIZE], symbol;
    //cin.getline(sentence, MAX_SIZE);
    //cin >> symbol;
    //size_t counter = 0;
    ////int length = strlen(sentence);
    ////cout << length;
    //for (int i = 0; sentence[i] != '\0'; ++i)
    //{
    //    if (sentence[i] == symbol)
    //    {
    //        counter++;
    //        sentence[i] = '*';
    //    }

    //}
    //cout << counter << endl;
    //cout << sentence  << endl;

//task 6
//char sentence[MAX_SIZE];
// cin.getline(sentence, MAX_SIZE);
// size_t cnt = 0;
// //char minWord[MAX_SIZE];
// //char maxWord[MAX_SIZE];
// //char currentWord[MAX_SIZE];
// if (sentence[0] == '.' || sentence[0] == '!' || sentence[0] == '?')
// {
//     cout << "0" << endl;
//     return 0;
// }
// for (size_t i = 0; sentence[i] != '.' && sentence[i] != '!' && sentence[i] != '?'; i++)
// {
//     /*if (sentence[i] == ' ')
//     {
//         cnt++;
//         if (strlen(currentWord) < strlen(maxWord))
//         {
//             strcpy_s(maxWord, strlen(currentWord), currentWord);
//         }
//         if (strlen(currentWord) > strlen(minWord))
//         {
//             strcpy_s(minWord, strlen(currentWord), currentWord);
//         }
//         continue;
//     }*/
//     if (sentence[i]== ' ')
//     {
//         cnt++;
//     }
//
// }
// cout << ++cnt << endl;

//task7
int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE] ;
int n;
cin >> n;
cout << "A= ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "B= ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }
    cout << "------------- ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<  A[i][j] + B[i][j]<< " " ;// за в) пишем 2*A[i][j] + 3*B[i][j];
        }
        cout << endl;
    }
  
    return 0;
}

    
 
 