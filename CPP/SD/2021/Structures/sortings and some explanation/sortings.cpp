#include <iostream>
//n = 4 => 10 1 2 3         => sum = c1*1 + c1*1 + c2*4 + c3*3 + c1*0 + c4*4
//n = 8 => 10 1 2 3 4 5 6 7 => sum = c1*1 + c1*1 + c2*8 + c3*7 + c1*0 + c4*8
//n = 8 => 1 2 3 4 5 6 7 10 => sum = c1*1 + c1*1 + c2*8 + c3*7 + c1*7 + c4*8

// sum = c1 + c2*n + c3*(n-1) + c1 + c4*n
// sum = 2*c1 + c2*n + c3*n - c3 + c4*n
// sum = 3*c1 + (c2 +c3 +c4)*n - c3

// sum = n
// O(n)

// 100n + 300
// k1 = 100, k2 =300
// n

// c1 = времето за изпълнение на операция присвояване
// c2 = времето за изпълнение на операция сравение (<)
// c3 = веремето за изпълнение на операция сравенение (>)
// c4 = веремето за изпълнение на операция ++
template<typename T>
void findMax(T *array, int arrayLength) {
    // 1
    // 1
    // 1
    T localMax = array[0];
    // i < arrayLength: 4
    // i < arrayLength: 8 + c3 * 7 + c1*0
    // i < arrayLength: 8 + c3 * 7 + c1*0
    //  ++i: 4
    //  ++i: 8
    //  ++i: 8
    for (int i = 1; i < arrayLength; ++i) {
        // 3
        // 7
        // 7
        if (array[i] > localMax) {
            // 0
            // 0
            // 7
            localMax = array[i];
        }
    }
}

template<typename T>
void bubbleSort(T *array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        for (int j = 0; j < arrayLength - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<typename T>
void selectionSort(T *array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        int index = i;
        for (int j = i + 1; j < arrayLength; j++) {
            if (array[j] < array[index]) index = j;
        }
        std::swap(array[i], array[index]);
    }
}

template<typename T>
void insertionSort(T *array, int arrayLength) {
    for (int i = 1; i < arrayLength; ++i) {
        for (int idx = i; idx > 0 && array[idx] < array[idx - 1]; idx--) {
            std::swap(array[idx], array[idx - 1]);
        }
    }
}

template<typename T>
void display(T * array, int arrayLength) {
    for (int i = 0; i != arrayLength; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    const int numbersLength = 5;
    int * numbers = new int[numbersLength];
    numbers[0] = 5;
    numbers[1] = 4;
    numbers[2] = 3;
    numbers[3] = 2;
    numbers[4] = 1;

//    bubbleSort(numbers, numbersLength);
//    selectionSort(numbers, numbersLength);
     insertionSort(numbers, numbersLength);
    display(numbers, numbersLength);
    

    delete[] numbers;
    return 0;
}