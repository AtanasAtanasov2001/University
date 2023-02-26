// УП-Практикум 08.12.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//TASK 1
// pointers and referance 

void swap(double* n1, double* n2) // swap (int &n1, int &n2)
{
   double temp = *n1; // same without * 
    *n1 = *n2;
    *n2 = temp;
}
//TASK 2
void Print(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
//TASK 3
void BubbleSort(double arr[], size_t size)
{
    bool swapped;
    for (size_t i = 0; i < size-1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < size - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                swap = true;
                swap(arr[i],arr[j])
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

void InsertionSort(double arr[], size_t size)
{
    int j
    for (int i = 0; i < size; i++)
    {
        double key = arr[i];

        for (j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void MegreSort(int arr1[], size_t size1, int arr2[], sizt_t size2)
{
    int arr3[100];
    int cnt1 = 0, cnt2 = 0;
    size_t i = 0;
    for (; cnt1 < size1 && cnt2 < size2; i++)
    {
        if (arr1[cnt1] < arr2[cnt2])
        {
            arr3[i] = arr1[cnt1++]
        }
        else
        {
            arr3[i] = arr2[cnt2++]
        }
    }
    while (cnt1 < size1)
    {
        arr3[i] = arr1[cnt1];
        i++;
        cnt1++
    }
    while (cnt2 < size2)
    {
        arr3[i] = arr2[cnt2];
        i++;
        cnt2++;
    }
    print(arr3, i);
}

int main()
{
    //    int a, b;
    //    cin >> a >> b;
    //    cout << "Before";
    //    cout << a << " " << b << endl;;
    //    swap(&a, &b); // same without &
    //    cout << "After";
    //    cout << a << " " << b << endl;
    
    // double arr[] = { 4, 3, 2, 10, 12, 1, 5, 6 };

    // size = sizeof(arr) / sizeof(*arr);
    // Print(arr, size);
    // BubbleSort(arr,size);//InstertionSort(arr,size);
    // Print(arr, size);

input();

   
}
 