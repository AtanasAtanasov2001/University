// Контролна работа 1 - УП - Атанас Атанасов  Фн 72028 
#include <iostream>

int main()
{
   /*
   Task 1 a)
   int DryCough, SoreThroat, NoSmell, PositiveCPR;
    double Temp;
    bool COVID33 = true;
   
    if (DryCough && (37, 5 <= Temp <= 40, 5) && SoreThroat || DryCough && NoSmell || PositiveCPR)
    {
        COVID33;
    }
    else
    {
        COVID33 = false;
    }
     */
  /* Task 1  b)
  int N;
    std::cout << "Enter a 3-digit number: ";
    std::cin >> N;

    int FirstDigit = (N / 100) % 10;
    int SecondDigit = (N / 10) % 10;
    int ThirdDigit = N % 10;

    bool Different = true;

    if (FirstDigit != SecondDigit != ThirdDigit)
    {
        std::cout << std::boolalpha << Different << std::endl;;
    }
    else
    {
        Different = false;
        std::cout << std::boolalpha << Different << std::endl;
    }*/

    //
    //Task 2 
    //int n;
    //std::cout << "Enter a number: ";
    //std::cin >> n;
    //int next = 0;// the next number in the row
    //int count = 1;
    //while (n != 1)
    //{
    //    if (n % 2 == 0)
    //    {
    //        next = n / 2;
    //    }
    //    else if (n % 2 != 0)
    //    {
    //        next = (3 * n) + 1;
    //    }

    //    n = next;
    //    count++;

    //}
    //
    //std::cout << "The row of Kolac has" << count <<"members" <<std::endl;

    int n;
    std::cout << "Enter a positive number: ";
    std::cin >> n;
    int numbers = n;
    std::cin >> numbers;

    return 0;
}
 
  
 