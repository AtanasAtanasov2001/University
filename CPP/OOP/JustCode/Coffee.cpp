// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
int Coffee(int *arr, int size, int i=0)
    {
    int finalSequence = 0;
    if (i == size)
    {
        if (arr[i] == 8)
        {
            return 1;
        }
        return arr[i];
    }
    else if (arr[i] == 3 && arr[i + 1] == 9 && arr[i + 2] == 7)
    {
            arr[i] = 6;
            arr[i+1] = 8;
            return (Coffee(arr + 3, size - 3, i));
    }
    else if (arr[i] == 8 && (i + 1 != arr[size]))
    {
            arr[i] = 8 / arr[i + 1];
            return (Coffee(arr + 1, size - 1, i));
    }   

    else if (arr[i] == 8 && (i + 1 == arr[size]))
            {
            arr[i] = 8 / arr[0];
            return (Coffee(arr + 1, size - 1, i));
           
            }
    cout << *arr << " ";
    return (Coffee(arr + 1, size - 1, i));
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    Coffee(arr, n, 0);

    return 0;
}
