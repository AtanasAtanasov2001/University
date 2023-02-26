#include <iostream>

const int MAX_SIZE = 10;
	
int index(char arr[],int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		
	}
	return i;
}
//1 2 3 4 5
void compare()
{
	char arr1[] = { "abcdefghij" }; new char*;
	char arr2[] = { "0123456789"}; new char*;

	int size = sizeof(arr1) / sizeof(arr1[0]);
	bool flag = false;
	for (size_t i = 0; i < size; i++)
	{
		if (index(new char[i],size) == index(new char[i], size))
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}
	if (flag)
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	delete new char;
}

//double inputMatrix()
//{
//	int size;
//	std::cin >> size;
//	double matrix[MAX_SIZE][MAX_SIZE];
//	size_t i = 0;
//	size_t j = 0;
//	for (i = 0; i < size; i++)
//	{
//		for (j = 0; j < size; j++)
//		{
//			std::cin >> matrix[i][j];
//		}
//	}
//	std::cout <<  std::endl;
//	return **matrix;
//}
int sumMainDiagonal(double **matrix,int size)
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += matrix[i][i];
	}
	return sum;
}
void removeRowsAndCols(double *matrix[] ,int size)
{
	int rows = size, cols = size;
	for (size_t rows = 1; rows <= size; rows++)
	{
		for (size_t cols = 1; cols <= size; cols++)
		{
			if (cols == size / 2)
			{
				matrix[rows][cols] = 0;
			}
			if (rows == size / 2)
			{
				matrix[rows][cols] = 0;
			}
			
		}
	}
}
void mainDiagonalsOfSubMatrix(double matrix[][], int size)
{
	bool equal = false;
	removeRowsAndCols(matrix, size);
	int i = 0, j = 0;
	
	int sumD1 = 0;
	int sumD2 = 0;
	int sumD3 = 0;
	
	while (i < size && j < size)
	{
		if (i == j)
			sumD1 += sumMainDiagonal(matrix[i][j], 2);
		else if (i < j)
			sumD1 += sumMainDiagonal(matrix[i][j], 2);
		else if (j < i)
			sumD1 += sumMainDiagonal(matrix[i][j], 2);
	}i++, j++;
	
	if (sumD1 == sumD2 == sumD3)
	{
		equal = true;
	}
	
	if (equal)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
}
//11    12        13 = 0 14     15
//21    22        21 = 0 24     25
//31= 0 32 = 0    33 = 0 34 = 0 35 = 0
//41    42        43 = 0 44     45
//51    52        53 = 0 54     55
 
struct Coordinates
{
	int X=0, Y=0;
	int beginning = (X, Y);
	int down = (X + 1, Y);
	int up = (X , Y + 1);
	int right = (X + 1, Y + 1);
	int left = (X - 1, Y - 1);	
};

void recSolution(double** square, struct Coordinates)
{
	if (Coordinates.beginning == {0,0})....
}


int main()
{
	//Task1 ----------------
	/*double matrix[][5] = { 1, 2, 3, 5, 5,
						    4, 5, 6, 5, 5,
						    7, 8, 9, 5, 5,
						    3, 4, 5, 5, 5,
						    4, 5, 6, 7, 7, };
	mainDiagonalsOfSubMatrix(matrix[5][5], 5);*/
	//std::cout << sumMainDiagonal(matrix, 5);
	//Task2 --------------				
	//compare();
	//Task3-------------------
	double square[5][5] = { 0, 1 ,1, 0 ,0,
							1, 1, 0, 1, 0,
							0 ,1, 1, 1, 0,
							0, 1, 0, 1, 0,
							0, 0, 1, 1, 1 };
	 
}

