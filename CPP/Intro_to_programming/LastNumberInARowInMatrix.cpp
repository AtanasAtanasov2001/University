#include <iostream>

//{1, 2 ,3 4}
// 3
int lenghtOfLastElements(double arr1[], double arr2[], int size2)
{
	int size1 = 6;
	
	int cnt = 0;

	//i=1
	//---------- 		arr1[size1-i]
	//------			arr2[size2-i]
	for (size_t i = 1; (i <= size1) && (i <= size2); i++)
	{
		if (arr1[size1 - i]  == arr2[size2 - i])
		{
			cnt += 1;
		}
		else
		{
			return cnt;
		}
	}
	return cnt;
}

int hasCommonEnding(double matrix[][6], double* array, int matrixSize, int arraySize)
{
	// double* arr1 = *matrix;
	// double* arr2 = *(matrix + 1);
	
	// int size1 = sizeof(arr1) / sizeof(arr1[0]);
	// int size2 = sizeof(arr2) / sizeof(arr2[0]);
	//std::cout << lenghtOfLastElements(*matrix, array,arraySize);

	//3//2
	//maxIndex = 0
	//maxValue = INT_MIN

	int maxIndex = 0;
	int maxValue = 0;
	for (size_t i = 0; i < matrixSize; i++)
	{
		int value = lenghtOfLastElements(*(matrix + i), array, arraySize);
		if (value > maxValue)
		{
			maxValue = value;
			maxIndex = i;
		}
		
	}
	return maxIndex;
}
double recFunc(double *array,int size)
{
	double proizvedenie = 1;
		if (size == 1)
		{
			return 1;
		}

		if ((*array >= *(array +1)) && (*(array+1) > 0) )
		{
			proizvedenie = *(array+1);
		}
	
	return proizvedenie * recFunc(array+1,size-1);
}
//1 2 3 4 5 
double boyan(double *arr, int size) {
	int curr = 1;

	if(size == 1){
		return 1;
	}else if (*(arr+1) > 0 && *arr > *(arr+1)) {
		curr = *(arr+1);
	}

	return boyan(arr+1, size-1) * curr;
}


int main()
{
	/*double array[] = { 2.1, 0, 9.9, 3, 1, -1, 4.5, 7 };
	int size = sizeof(array) / sizeof(*array);
	std::cout << recFunc(array, size) << std::endl;*/
	
	
	double arr1[][6] = {  0,1,3,7,4,5,
					   1,2,6,3,4,5	};			
									
	double arr2[] = { 2,3,4,5 };
	// int size1 = sizeof(arr1) / sizeof(arr1[0]);
	 int size2 = sizeof(arr2) / sizeof(arr2[0]);
	// std::cout << lenghtOfLastElements(arr1, arr2,size1,size2);
	 std::cout << hasCommonEnding(arr1, arr2, 2, size2);
	
}

