

#include <iostream>
const int MAX_SIZE= 256;

void Task1()
{
	//int a, int b;
	// 123 .. 22314
	/*if ((a == b / 100) || (a == b % 1000) || (a == ((b % 10000) / 10)));
	if ((b % 10 == ((b % 100) / 10 + (b % 1000)) / 100) && ((b % 100) / 10 == (b % 1000) / 100) + (b % 10000) / 1000)) ...);
	*/
	int array[MAX_SIZE];
	int n;
	std::cin >> n;
	bool flag = false;
	for (int i = 0; i <= n; i++)
	{
		std::cin >> array[i];
		
		if ((array[i] == array[i-1] - 5) && (i>0))
		{}
		else
		{
			flag = true;
		}
	}
	if(flag){
		std::cout << "ne staa" << std::endl;
	}else {
		std::cout << "baca" << std::endl;
	}
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
	// matrix[i][i]
	for (size_t rows = 0; rows < size; rows++)
	{
		for (size_t cols = 0; cols < size; cols++)
		{
			std::cout << matrix[rows][cols] << " ";
		}
		std::cout << std::endl;
	}
}

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

// 00 01 02
// 12 11 10
// 20 21 22

int aboveDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
	int max = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
			}
		}
	}
	return max;
}

int underDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
	int min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (min > matrix[j][i])
			{
				min = matrix[j][i];
			}
		}
	}
	return min;
}
// 1 2 3
// 6 5 4
// 7 8 9
void TASK2(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
	int a = aboveDiagonal(matrix, size);
	int b = underDiagonal(matrix, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (matrix[i][j] == a)
			{
				matrix[i][j] = b;
			}

			if (matrix[j][i] == b)
			{
				matrix[j][i] = a;
			}
		}
	}
	printMatrix(matrix, size);
	std::cout << std::endl;
	std::cout << a << " " << b << std::endl;
}
// a -b - v - g - d- pos 5
void Transition(char* arr, int pos)
{
	for (size_t i = pos;arr[i] != '\0'; i++)
	{
		arr[i] = arr[i + 1];
	}
}
void task3(char* arr, int size,char sym)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == sym)
		{
			Transition(arr, i);
		}
	}
	std::cout << arr << std::endl;
}
void printIndex(char* sentence, int size, char symbol)
{
	int i = 0;
	while (i < size)
	{
		if (sentence[i] == symbol )
		{ 
			if(i < size)
			{
				std::cout << "The symbol:" << symbol << "is present at index " << i << std::endl;
				
			}	
			else		
			{
				std::cout << "The symbol is not present in the array" << std::endl;
			}	
		}
		i++;	
	}

}
bool EvenEdinici(int n,int cnt1)
	{
		
		if (n != 0)
		{
			cnt1 += n % 2;	
		}
		else
		{
			if (cnt1 % 2 == 0)
				{
					return true;
					//std::cout << "even number of 1" << std::endl;
				}
			else
				{
					return false;
					//std::cout << "the number of 1 is not even" << std::endl;
				}
		}
		
		return EvenEdinici(n /= 2,cnt1);
	}
//10 = 1010
//11 = 

struct Box
{
	int number;
	char arr[MAX_SIZE];
	bool taken;

	void ToString()
	{
		std::cout << "The number of the box is: " << number << std::endl;
		std::cout << "The content of the box is: " << arr << std::endl;
		std::cout << "Is the box taken: "<<std::boolalpha << taken << std::endl;
	}

	bool Ocupied()
	{
		if (taken)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//6... 1{..} 2..3...6
//4 2 7 9 3 
//2 4 7 3 9 11
//

void SortArrayOfBoxes(Box boxes[MAX_SIZE], int size)
{
	bool flag = true;

	while (flag)
	{
		flag = false;

		for (size_t i = 0; i < size - 1; i++)
		{
			if (boxes[i].number > boxes[i + 1].number)
			{
				Box temp;
				temp = boxes[i];
				boxes[i] = boxes[i + 1];
				boxes[i + 1] = temp;
				flag = true;
			}
		}
	}
}
int main()
{	//Task2
	/*int matrix[MAX_SIZE][MAX_SIZE], size;
	std::cout << "size"; 
	std::cin >> size; 

	fillMatrix(matrix,size);
	std::cout << std::endl;
	printMatrix(matrix, size);
	std::cout << std::endl;
	TASK2(matrix, size);*/
	//---------------
	//task 3
	char arr[] = { "pornohubo" };
	char symbol = 'o';
	int size = sizeof(arr) / sizeof(arr[0]);
	task3(arr, size, symbol);
	printIndex(arr, size, symbol);

	//Task4
	/*int arr[MAX_SIZE];
	int n;
	std::cin >> n;
	bool flag = false;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		if (EvenEdinici(arr[i], 0))
			{
			flag = true;
			std::cout << arr[i] << std::endl;
			}
	}
	if (flag == false)
	{
		std::cout << "error404" << std::endl;
	}*/
	//----------------
	//task5

	/*Box a, b, c;

	a.number = 5;
	b.number = 2;
	c.number = 69;

	Box Boxes[] = { a,b,c };

	SortArrayOfBoxes(Boxes, 3);
	std::cout << Boxes[0].number << Boxes[1].number << Boxes[2].number << std::endl;;*/
}

