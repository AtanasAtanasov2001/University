#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <Windows.h>
const int MAX_SIZE = 256;

struct Progress_Bar
{
	char array[MAX_SIZE];
	int size;
	int currentProgress;
	bool ind;
	char startChar;
	char endChar;
	char fillChar;
	char nullChar;

	void Input()
	{
		std::cout << "Size: ";
		std::cin >> size;

		std::cout << "Indicator (0 OR 1): ";
		std::cin >> ind;

		std::cout << "Symbol for the beggining: ";
		std::cin >> startChar;

		std::cout << "Symbol for the ending: ";
		std::cin >> endChar;

		std::cout << "Symbol for the progress until now: ";
		std::cin >> fillChar;

		std::cout << "Symbol for the empty symbol: ";
		std::cin >> nullChar;

		array[0] = startChar;
		for (int i = 1; i <= size; i++)
		{
			array[i] = nullChar;
		}
		array[size + 1] = endChar;
	}

	void PrintArr(int percent)
	{
		bool hasReachedNullChar = false;
		for (int i = 0; i <= size + 1; i++)
		{
			if ((array[i] == nullChar || array[i] == endChar) && hasReachedNullChar == false && ind)
			{
				hasReachedNullChar = true;
				std::cout << percent << '%';
			}
			std::cout << array[i];
		}
		std::cout << std::endl;
	}

	void ClearConsole()
	{
		/*for (int i = 0; i <= 100; i++ ) {
			std::cout << std::endl;				 // <- tova printi nai-dolu na konzolata
		}*/
		// #include <Windows.h>  i system ("cls") ne sme gi uchili, vidyah gi v neta i izglejda po-krasivo!
		system("cls");
	}

	void FillArray()
	{

		for (int i = 1; i <= currentProgress; i++)
		{
			array[i] = fillChar;
		}
	}

	void Start()
	{
		const int T = 50;
		for (int i = 0; i <= 100; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(T));
			currentProgress = floor((size * i) / 100);
			FillArray();
			ClearConsole();

			PrintArr(i);

		}

		// 100 -> 1% = 1%
		// 10 -> 1% = 10%
		// (size*i)/100
		// 0.1 = 0......1 = 1...1.9 = 1...
	}

};