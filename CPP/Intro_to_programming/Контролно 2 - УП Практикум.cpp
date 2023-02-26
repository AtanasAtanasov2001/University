// Контролно 2 - УП Практикум.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fact(int n)
{
    if (n > 1)
    {
       return n * fact(n - 1);
    }
     return 1;
}
int Task1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return fact(n) + Task1(n - 1);
}
int TestTask1()
{
    int n;
    std::cout << "enter a number";
    std::cin >> n;
    std::cout << Task1(n) << std::endl;
    return 0;
}

void Task2(const char* arr)
{
   static int cnt_Cap = 0;
   static int cnt_Digits = 0;
   static int cnt_Small = 0;

    if (*arr == '\0')
    {
        std::cout << "Digits: " << cnt_Digits << std::endl;
        std::cout << "Capitals: " << cnt_Cap << std::endl;
        std::cout << "Small: " << cnt_Small << std::endl;
        return;
    }

    if (*arr >= 'A' && *arr <= 'Z')
    {
        cnt_Cap++;
    }
    else if (*arr >= 'a' && *arr <= 'z')
    {
        cnt_Small++;
    }
    else if (*arr >= '0' && *arr <= '9')
    {
        cnt_Digits++;
    }
    Task2(arr + 1);
}
void TestTask2()
{
    char arr[] = "8AFGcda567";
    return Task2(arr);
}

unsigned int Task3(unsigned int num)
{
    unsigned int res = num & (num - 1);
    return num - res;
}

unsigned int TestTask3()
{
    unsigned int n;
    std::cin >> n;
    
    std::cout << Task3(n);
    return 0;
}


int main()
{
    //TestTask1();
    
    //TestTask2();
    
    //TestTask3();
    return 0;
}
    

