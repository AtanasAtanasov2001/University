// Задачи - практикум 27.10.20.cpp :
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;
int main()
{

    /*
    int n; Задача 1// find the biggest negative number
    cout << "Enter a number: ";
    cin >> n;
    int bnn = INT_MIN;
    int number1;
        while (n)
        {
            cout << "Enter a number to compere with bnn: "<< endl;
            cin >> number1;

            if (number1 > bnn && number1 < 0)
            {
                bnn = number1;
            }
                --n;
        }
        cout << "The biggest negative number is " << bnn << endl;
        */
        /*Задача 2// find n!
        int n;
        cout << "Enter a number: ";
        cin >> n;
        int n_fact = 1;

        while (n > 0)
        {

            n_fact = n_fact * n;

            --n;
        }
        cout << "The factorial of the entered number is: "<< n_fact << endl;
        */
        /*
        Задача 3// show the first n members of a row
            int n;
        cout << "Enter a number: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout  << (i * i) + (3 * i) << endl;
        }
        */
        /* Задача 4// find a^n
        int a, n, newnumber = 1;
        cout << "enter a real number ";
        cin >> a;
        cout << "enter a natural number ";
        cin >> n;
        cout << a << "^" << n << " = ";

        while (n != 0) {
            newnumber *= a;
            --n;
        }


        cout << newnumber << endl;
        */
        /*
        int n, ; Задача 5// find the n number from the fibonachi row
            cout << "Enter a number: ";
            cin >> n;
        int a = 1;
        int b = 1;
        int result;
        for (int i = 2; i < n; i++)
        {
            result = a + b;
            a = b;
            b = result;

        }
        cout << "The corresponding number taken from the row of Fibonachi is: " << result << endl;
        */
        /* Задача 6// find the multyplication of a numbers in interval
        int a, b, result = 1;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        for (; a <= b; a++){
            result = a;}
        cout << "The multiplication of the numbers between a and b is:  " << result << endl;
        */
        /* Задача 7// check if a number if prime
        int a, b;
        bool isPrime = true;

        cout << "Enter a number: ";
        cin >> b;
        if (b == 0 || b == 1) {
            isPrime = false;
        }
        else {
            for (a = 2; a <= b / 2; ++a) {
                if (b % a == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            cout << b << " is a prime number";
        else
            cout << b << " is not a prime number";
            */
            /* Задача 8// find the prime numbers in a interval
            int p, q , i;
            bool isPrime = true;

            cout << "Enter two numbers (intervals): ";
            cin >>p >> q ;

            cout << "\nPrime numbers between " << p << " and " << q  << " are: " << endl;

            while (p < q)
            {
                isPrime = true;
                if (p == 0 || p == 1) {
                    isPrime = false;
                }
                else {
                    for (i = 2; i <= p / 2; ++i) {
                        if (p % i == 0) {
                            isPrime = false;
                            break;
                        }
                    }
                }

                if (isPrime)
                    cout << p << " ";

                ++p;
            }
            */
            /* Задача 9// create a floyd triangle
            int n, number = 1;
            cout << "Enter a number: ";
            cin >> n;
            for (int row = 0; row < n; row++)
            {
                for (int cols = 0; cols <= row; cols++)
                {
                    cout  << number << " ";
                    number++;
                }
                cout << endl;
            }
            */
            /* Задача 10
                int n ;
                cout << "Enter a number: ";
                cin >> n  ;
                char a = 'X',b='Y';

                for (int i = 0; i <= n - 2; i++)
                {
                    for (int q = 0; q <= i && q <= n - 2; q++)
                        cout << a << " ";
                    for (int q = 0; q <= n - i - 2; q++)
                        cout << b << " ";
                    cout << endl;
                }
            */
            /* Задача 11// find the binary value of a number
                int  n,i=0,a=1;
                cout << "Enter the number to convert: ";
                cin >> n;
                for (  ; n ; n/=2)
                {
                    i += (n % 2) * a;
                    a*=10;

                }
                cout << "Binary of the given number= " << i<<endl;
             */  
             /* Задача 0
        int n,number1,number2,number3 ,multyplication,collection;
        cout << "Enter a number: ";
        cin >> n;
        int product = 1;
       
       number1 = n  % 10;
        number2 = (n   / 10) % 10;
        number3 = (n  / 100) % 10;
        
        multyplication = number1 * number2 * number3;
        collection = number1 + number2 + number3;
        while (n)
        {
            product *= n % 10;
            n /=10;
        }
        if (   multyplication<1000 && multyplication>100)
        { 
            cout << "YES " << (multyplication - collection) << endl;
        }
        else
        {
            cout << "NO " << multyplication << endl;
        }
        product++;
        */

}
 


