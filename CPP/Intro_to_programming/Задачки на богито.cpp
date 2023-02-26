// Задачки на богито.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int MAX_SIZE = 150;


int main()
{
    //    int array[MAX_SIZE];
    //    // Задача 1.
    //    int n, i;
    //    bool ThereAreStudentsWithPoorGrade = false;
    //    cout << "Enter a size of the array";
    //    cin >> n;
    //    cout << "Enter the elements of the array";
    //
    //    for (i = 0; i < n; i++)
    //        cin >> array[i];
    //
    //    for (i = 0; i < n; i++)
    //    {
    //        if (array[i] > 3)
    //        {
    //            cout << "There are no students with Poor grade";
    //            break;
    //        }
    //        else if (array[i] < 3)
    //        {
    //            cout << "There are students with Poor grade - " << array[i] << " this student has poor grade!";
    //            break;
    //        }
    //    }
    //}

        //Задача 2
    int array[MAX_SIZE];
    int sum = 0, i, n,j;
    cout << "Enter a size of the array";
    cin >> n;
    cout << "Enter the elements of the array";

    for (i = 0; i < n; i++)
        cin >> array[i];
    for (i = 0; i < n; i++)
    {
        sum += array[i];
        if (array[i] > sum / n)
        {
            cout << " " << i;
        }
    }
}
        
   
     
 

 