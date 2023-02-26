// УП - семинар 29.10.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

 

#include <iostream>
const int MAX_SIZE = 100;

int main() {


	// Task 1:
	// FizzBuzz
	// 3,5 
	// Input a number:
	// -> 1-n => 
	//         - "Fizz" -> i%3 = 0
	//         - "Buzz" -> i%5 = 0
	//         - "FizzBuzz" -> i%3 = 0 && i%5 = 0
	//         - "i" -> i%3 != 0 && i%5 != 0

	int n;
	const int K1 = 3, K2 = 5;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		if (i % K1 == 0 && i % K2 == 0) {
			std::cout << "FizzBuzz ";
			continue;
		}
		if (i % K1 == 0) {
			std::cout << "Fizz ";
			continue;
		}
		if (i % K2 == 0) {
			std::cout << "Buzz ";
			continue;
		}
		std::cout << i << " ";
	}

	//int array[10];
	//array[0]-> array + 0 * sizeof(int)
	//array[1]-> array + 1 * sizeof(int)

	// length is const 
	//const int SIZE = 10;
	//int numbers[10], numbers2[SIZE];
	//int a = 10;
	//std::cin >> a;
	//int invalid[a];

	// 
	//int second[] = {1, 2, 3};
	//int third[5] = {};
	//int fourth[5] = {1, 1, 1};

	// accessing data
	// array[index] -> 

	//numbers[0] - first element
	//numbers[SIZE-1] - last element

	//
	//int a;
	//std::cin >> a;
	//int array[10];
	//std::cin >> array; - invalid

	//for (int i = 0; i < 10; ++i) {
	//	std::cin >> array[i];
	//}

	//std::cout << "\n";
	//for (int i = 0; i < 10; ++i) {
	//	std::cout << array[i] << " ";
	//}
	//std::cout << "\n";

	//array[2] = 10;
	//array[3] = 1;
	//array[4] = array[2] + array[3];

	// Task 2:
	// Input: length of array (0 < length < 100) + array elements
	// Output: max & min of elements

	//int number[100], length;
	//std::cout << "Enter array length: ";
	//std::cin >> length;
	//while (length <= 0 || length > 100) {
	//	std::cout << "Invalid length (should be in [1;100]): ";
	//	std::cin >> length;
	//}

	//int max, min, index = 0, sum = 0;
	//while (index < length) {
	//	std::cin >> number[index];
	//	index++;
	//}
	//bool arrayIsSorted = true;
	//for (int i = 0; i < length; ++i) {
	//	std::cin >> number[i];
	//	if (i != 0) {
	//		if (number[i] < number[i - 1]) {
	//			arrayIsSorted = false;
	//		}
	//	}

	//	sum += number[i];
	//	if (i == 0) {
	//		max = number[i];
	//		min = number[i];
	//		continue;
	//	}

	//	if (number[i] > max) {
	//		max = number[i];
	//	}

	//	if (number[i] < min) {
	//		min = number[i];
	//	}
	//}
	//std::cout << (arrayIsSorted ? "Array is sorted!" : "Array is not sorted!") << std::endl;
	//std::cout << "MAX: " << max << std::endl << "MIN: " << min << std::endl << "SUM: " << sum << std::endl;

	// 1 2 5 -10 20
	//bool isSorted = true;
	//for (int i = 0; i < length; ++i) {
	//	if (i != 0) {
	//		if (number[i] < number[i - 1]) {
	//			std::cout << "Array is not sorted!\n";
	//			isSorted = false;
	//			break;
	//		}
	//	}
	//}
	//if (isSorted) std::cout << "Array is sorted!\n";

	// Task 3:
	// Bubble sort
	// Input: length (0 < length <= 100) and array
	// Output: the sorted array

	//int length, array[MAX_SIZE];
	//std::cout << "Enter array length: ";
	//std::cin >> length;
	//while (length <= 0 || length > MAX_SIZE) {
	//	std::cout << "Invalid length (should be in [1;100]): ";
	//	std::cin >> length;
	//}

	//for (int i = 0; i < length; ++i) {
	//	std::cin >> array[i];
	//}

	//for (int i = 0; i < length - 1; ++i) {
	//	// Last i elements are already sorted => we don't need to iterate over them
	//	for (int j = 0; j < length - i - 1; ++j) {
	//		if (array[j] > array[j + 1]) {
	//			int temp = array[j];
	//			array[j] = array[j + 1];
	//			array[j+1] = temp;
	//		}
	//	}
	//}
	//
	//std::cout << std::endl << "Sorted array:" << std::endl;
	//for (int i = 0; i < length; ++i) {
	//	std::cout << array[i] << " ";
	//}

	//std::cout << std::endl;

	// Task 4:
	// Input: number (integer)
	// Output: whether each digit is the sum of the next two digits
	// The number is < 10000000000

	//int digits[10];
	//int number;
	//std::cout << "Enter the number:\n";
	//std::cin >> number;
	//int length = 0;
	//number = abs(number);
	//while (number > 0) {
	//	//int lastDigit = number % 10;
	//	//digits[length] = lastDigit;
	//	//length++;
	//	
	//	digits[length++] = number % 10;
	//	number = number / 10;
	//}

	//for (int i = 0; i < length; ++i) {
	//	std::cout << digits[i] << " ";
	//}
	//std::cout << std::endl;

	//for (int i = length - 1; i >= 2; --i) {
	//	if (digits[i] != digits[i - 1] + digits[i - 2]) {
	//		std::cout << "NO\n";
	//		system("pause");
	//		return 0;
	//	}
	//}

	//std::cout << "YES\n";

	//int last = number % 10, secondLast = (number / 10) % 10;
	//number = number / 100;
	//bool yes = true;
	//while (number != 0) {
	//	int currentDigit = number % 10;
	//	if (currentDigit != last + secondLast) {
	//		//std::cout << "NO\n";
	//		//system("pause");
	//		//return 0;
	//		yes = false;
	//		break;
	//	}
	//	last = secondLast;
	//	secondLast = currentDigit;
	//	number /= 10;
	//}
	////std::cout << "YES\n";

	//std::cout << (yes ? "YES" : "NO") << std::endl;

	// Task 5:
	// Enter 3 symbols
	// Output: All possible combinations of the symbols

	system("pause");
	return 0;
}
 


