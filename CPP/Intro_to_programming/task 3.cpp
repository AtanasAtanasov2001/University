// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n, number = 0, previous = 0;
	double sum = 0;
	cin >> n;
	bool contains = false;
	for (int i = 0; i < n; i++)
	{
		if (contains)
		{
			cin >> number;
			sum += number;
		}
		else {
			//bool contains = false;
			previous = number;
			if (i == 0)
			{
				cin >> number;
				sum += number;
				continue;
			}
			cin >> number;
			sum += number;
			if (previous / number < 1) // checks if the previos number has more digits than the current one
			{
				continue;
			}
			while (previous != 0 && number != 0)
			{
				if (number % 10 == previous % 10)
				{
					previous /= 10;
					number /= 10;
					contains = true;
				}
				else
				{
					contains = false;
					previous /= 10;
				}
				if (!contains && number / 10 == 0)
				{
					break;
				}
			}
		}
	}
	if (contains)
	{
		cout << "YES\n";
		cout << double(sum / n);
	}
	else cout << "NO";
}
 
