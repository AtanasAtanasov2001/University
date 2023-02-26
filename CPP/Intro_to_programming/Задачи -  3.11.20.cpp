// УП практикум - 3.11.20.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    /* zadacha 1// show 1+11+111... n times
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int toprint = 1;
    for (int row = 0; row < n; ++row)
    {
        if(row==n)
        {
            cout << toprint;
            break;
        }
     cout << toprint<< " + ";
     toprint = (toprint * 10) + 1;
     cout<<endl;
        
    }
    */
    /* zadacha 2// find the sum of the numbers between 100-200 that can be divided by 9
    int collection = 0;
    for (int i = 100; i <= 200; ++i)
    {
        if (i % 9 == 0)
        {
            collection += i;
        }
    }
    cout << collection << endl;
    */
    /* zadacha 3// check if a number is a palindrome
    int n,  number, digit, reversed = 0;

    cout << "Enter a number: ";
    cin >> number;
    n = number;

    while (number != 0) 
    {
        digit = number % 10;
        reversed = (reversed * 10) + digit;
        number = number / 10;
    } 

    cout << " The reverse of the number is: " << reversed << endl;

    if (n == reversed)
        cout << " The number is a palindrome.";
    else
        cout << " The number is not a palindrome.";
     */   
    
    /* zad 4// reverse a number
    int n;
    cout << "enter a number: ";
    cin >> n;
    int reversed = 0;
    int copyn = n;
    while (copyn != 0)
    {
        reversed = reversed * 10 + copyn % 10;
        copyn /= 10;
    }
    cout << reversed;
    */
    /* zadacha 5// make a picture   *
                                   ***
                                    * 
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int space = 0; space < n - row; space++)
        {
            cout << ' ';
        }
        for (int stars = 0; stars < 2*row - 1; stars++)
        {
            cout << "*";
        }
        
        cout << endl;
    }
    for (int row = 1; row < n; row++)
    {
        for (int space = 0; space < row; space++)
        {
            cout << ' ';
        }
        for (int stars = 0; stars < 2*(n-row)-1; stars++)
        {
            cout << "*";
        }
        cout << endl;
    }
    */
    /* zadacha 6/ check if the first and the last digit of a number are equal
    int n1, n2;
    cin >> n1;
    n2 = n1 % 10;
    while (n1 >= 10)
    {
        n1=n1 / 10;
    }
    cout << std::boolalpha << (n1 == n2) << endl;
    return 0;
     */

}
 
