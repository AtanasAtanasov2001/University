// УП-практикум 10.11.20
// ||

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int arr[10], n, i, max, min;
    cout << "Enter a size of the array";
    cin >> n;
    cout << "Enter the elements of the array";

    for (i = 0; i < n; i++)
        cin >> arr[i];
    max = arr[0];

    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    min = arr[0];

    for (i = 0; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    cout << "The largest element is: " << max << endl;
    cout << "The smallest element is: " << min << endl;

    return 0;
}

