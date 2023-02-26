// УП - 01.12.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//int sum(int x, int y);
//char sum(int x, char y);
//int sqare(int x);
//void increment(int x);

//task1
size_t Abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}
double pow(double x, size_t p)
{
    double powered = 1
    while (p)
    {
        powered *= x;
        
        p--;
    }
    return powered;
}
double min(double x, double y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
double max(double x, double y)
{
    return(x >= y) ? x : y;
}
double MinOF3(double x, double y, double z)
{
    return min(x, min(y, z));
}
double MaxOF3(double x, double y, double z)
{
    return max(max(x,y),z);
}
bool isAlpha(char symbol)
{
    /*
    if (('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z'))
    {
        return true;
    }
    return false;*/
    return ('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z');
}
bool isDigit(char x) 
{
    return ('0'<= x && '9' <= x);
}
double average(int x, int y)
{
    return ((double)(x + y) / 2.0);
}
 void testTask1
        //abs
        cout << "------abs------" << endl;
        cout << Abs(-5) << endl;
        cout << Abs(3) << endl;
        //pow
        cout << "------Pow------" << endl;
        cout << pow(2,3) << endl;
        cout << pow(-3,3) << endl;
        //min
        cout << "------min------" << endl;
        cout << min (5 ,-6) << endl;
        cout << min(2 , 2) << endl;
        //max
        cout << "------max------" << endl;
        cout << max(5 , -6) << endl;
        cout << max(2 , 2) << endl;
        //minof3
        cout << "------minof3------" << endl;
        cout << MinOF3(16, 21, 30) << endl;
        cout << MinOF3(5, 3, 8) << endl;
        //maxof3
        cout << "------maxof3------" << endl;
        cout << MinOF3(16, 21, 30) << endl;
        cout << MinOF3(5, 3, 8) << endl;
        //IsAlpha
        cout << "------IsAlpha------" << endl;
        cout << std::boolalpha<<isAlpha('t') << endl;
        cout << std::boolalpha << isAlpha ('3')<< endl;
        cout << std::boolalpha << isAlpha('\0') << endl;
        //Isdigit
        cout << "------IsDigit------" << endl;
        cout << std::boolalpha << isDigit('t') << endl;
        cout << std::boolalpha << isDigit('3') << endl;
        cout << std::boolalpha << isDigit('\0') << endl;
        //average
        cout << "------average------" << endl;
        cout <<  average(5,8) << endl;
        cout << average(3.14, 36) << endl;


//task2
//unsigned int == size_t(4B)
bool Isprime(size_t x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
        
    }return true;
}
bool areConnectedPrimes(size_t x, size_t y)
{
    return(Isprime(x) && Isprime(y) && x + 2 == y);
}
void TestTask2
    cout << std::boolalpha << areConnectedPrimes(3, 5) << endl;
    cout << std::boolalpha << areConnectedPrimes(11,13) << endl;
    cout << std::boolalpha << areConnectedPrimes(4, 5) << endl;
int main()
{
  //TestTask1()
  //TestTask2()  
    return 0;
}
//explanation
                /*int a, b;
            cin >> a >> b;
            cout << sum(a, b) << endl;
            int result = sum(a, b);
            cout << sqare(a) << endl;*/
            int a = 10;
            increment(a);
            cout << a << end;
 int sum(int x, int y)// ako prom sa vremenni moje i sum()
                                            //int... i t.n
{
   return x + y;
}
 int sum(int x, char y)
 {
     return x + y;
 }
int sqare(int x)
{
    return x * x;
}
void increment(int x)
{
    //a++;
    cout << (x + 1) << endl;
    return;
}