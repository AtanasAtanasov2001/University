// УП - семинар 05.11.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const unsigned int SIZE_MAX_PASCAL = 50;
const unsigned int SIZE_OF_ARRAY = 5;
int main()
{
	//// GCD while:
	//int number1, number2, temp1, temp2;
	//std::cout << "Enter two numbers for GCD calculation:\n";
	//std::cin >> number1 >> number2;
	//temp1 = number1;
	//temp2 = number2;

	//while (number1 != number2) {
	//	if (number1 > number2) {
	//		number1 -= number2;
	//		continue;
	//	}
	//	number2 -= number1;
	//}
	//std::cout << "GCD: " << number1 << std::endl;

	//if (temp2 > temp1) {
	//	int temp = temp2;
	//	temp2 = temp1;
	//	temp1 = temp;
	//}

	//int gcd = 0;
	//for (int i = 1; i <= temp2; ++i) {						++i = 1 + i/ i++ = i + 1
	//	if (temp1 % i == 0 && temp2 % i == 0) {					a=12/b=a++
																
	//		gcd = i;
	//	}
	//}

	//std::cout << "GCD: " << gcd << std::endl;
	// Task 6:
	/*char startLetter, endLetter, skipLetter;
	int wordCount = 0;
	std::cin >> startLetter >> endLetter >> skipLetter;

	for (char firstLetter = startLetter; firstLetter <= endLetter; ++firstLetter) {
		if (firstLetter == skipLetter) {
			continue;
		}
		for (char secondLetter = startLetter; secondLetter <= endLetter; ++secondLetter) {
			if (secondLetter == skipLetter) {
				continue;
			}
			for (char thirdLetter = startLetter; thirdLetter <= endLetter; ++thirdLetter) {
				if (thirdLetter == skipLetter) {
					continue;
				}
				std::cout << firstLetter << secondLetter << thirdLetter << " ";
				++wordCount;
			}
		}
	}
	std::cout << wordCount << std::endl;*/

	//// Safe cast:
	//char a = 'd';
	//std::cout << '#' << " " << int('#') << std::endl;
	//bool b = true;
	//std::cout << std::boolalpha << b << " " << int(b) << std::endl;


	//// Unsafe conversion (cast):
	//double n = 3.15;
	//std::cout << n << " " << int(n) << std::endl;

	//system("pause");
	//// Pascal triangle
	//// input: height
	//// output: the triangle with the input height

	//int height;
	//std::cin >> height;

	//// [row][col]
	//int pascalTriangle[SIZE_MAX_PASCAL][SIZE_MAX_PASCAL];
	//for (int i = 0; i < SIZE_MAX_PASCAL; ++i)
	//	for (int j = 0; j < SIZE_MAX_PASCAL; ++j)
	//		pascalTriangle[i][j] = 0;

	//for (int i = 0; i < height; ++i) {
	//	for (int j = 0; j <= i; ++j) {
	//		if (i == j || j == 0) {
	//			pascalTriangle[i][j] = 1;
	//		}
	//		else {
	//			pascalTriangle[i][j] =
	//				pascalTriangle[i - 1][j] +
	//				pascalTriangle[i - 1][j - 1];
	//		}
	//	}
	//}

	//for (int i = 0; i < height; ++i) {
	//	for (int j = 0; j <= i; ++j)
	//		std::cout << pascalTriangle[i][j] << " ";
	//	std::cout << std::endl;
	//};
	 
	//bool isPrimary(int number)
	//{
	//	for (int div = 2; div <= sqrt(number); ++div)
	//	{
	//		if (number % div == 0) {
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	//int sumOfDivisors(int number) {
	//	int sumOfDiv = 0;
	//	for (int div = 1; div <= number / 2; ++div)
	//	{
	//		if (number % div == 0) {
	//			sumOfDiv += div;
	//		}
	//	}
	//	return sumOfDiv;
	//}

	//int main() {
	//	//Task 5:
	//	//Input: n = 12, k = 15
	//	//Output : 16

	//	int n, k, result;
	//	std::cout << "Enter n & k (integers): ";
	//	std::cin >> n >> k;

	//	for (int i = n + 1; ; ++i)
	//		if (sumOfDivisors(i) == k) {
	//			std::cout << i << std::endl;
	//			break;
	//		}

	//	std::cout << "23 is a primary number: " << std::boolalpha << isPrimary(23) << std::endl;

//// Reverse an array of integers:
//int arrayToReverse[SIZE_OF_ARRAY];
//for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
//	std::cin >> arrayToReverse[i];
//}
//
//// start = 0, end = SIZE_OF_ARRAY - 1
//// start += 1, end -= 1
//// start < end
//
//int start = 0, end = SIZE_OF_ARRAY - 1;
//while (start < end) {
//	int temp = arrayToReverse[start];
//	arrayToReverse[start] = arrayToReverse[end];
//	arrayToReverse[end] = temp;
//
//	start++;
//	end--;
//}
//
////for (int start = 0, end = SIZE_OF_ARRAY - 1; start < end; start++, end--) {
////	int temp = arrayToReverse[start];
////	arrayToReverse[start] = arrayToReverse[end];
////	arrayToReverse[end] = temp;
////}
//
//for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
//	std::cout << arrayToReverse[i] << " ";
//}
	//return 0;
}

 