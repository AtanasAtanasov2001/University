#include <iostream>

template <typename T>
void sort (T* array, int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (size_t i = 0; i < n - 1 ; i++)
        {
            if (!(array[i] < array[i+1]))
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                flag = true;
            }
        }
    }
}

void printArr(int* array,int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i]<< " ";
    }
    
}
int main()
{
    int array[] = {2,5,8,1,13};
    //int n = sizeof(array)/sizeof(array[0]);
    sort (array,5);
    std::cout << "The array, using bubble sort is: ";
    printArr(array,5);
}