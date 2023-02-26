// Кантролно 2 - УП.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int MAX_SIZE = 100;
const int MAX_MATRIX_SIZE = 10;
const int MIN_MATRIX_SIZE = 4;
int Matrix_Input()
{
	int array[MAX_SIZE];
	for (int i = 0; i <= MIN_MATRIX_SIZE && i >= MAX_MATRIX_SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return 0;
}

char Capitalize(char *str)
{
	if (*str == ']')
	{
		*str = 0;
	}
	*str -= 32;
	return Capitalize (str+1);
}

char Task2(char *arr)
{
	int i;
	if (arr[i] == '[' || arr[i] == ']')
	{
		arr[i] == 0;
		Capitalize(arr+1);
	}
	std::cout << "There are not sqare brackets in the array" << std::endl;
	i++;

std::cout << "The final array is:" << arr << std::endl;
return 0;

}
char TestTask2()
{
	char sentence[MAX_SIZE];
	
	std::cin.getline (sentence,MAX_SIZE);

	return Task2(sentence);
}

double Task3(double *arr, size_t sum)
{

}
int main()
{
	TestTask2();
}

