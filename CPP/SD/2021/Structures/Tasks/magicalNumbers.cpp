#include <iostream>
#include <vector>
#include <array>

// Едно число ще наричаме магическо, ако всеки две негови съседни цифри имат разлика точно 2. 
// Например числата 246, 131 и 86 са магически. Всички едноцифрени числа са също магически. 
// По дадено число N трябва да изведете всички магически числа по-малки или равни на N във възходящ ред.

const int countDigits(int number) {
    int cnt = 0;
    while(number != 0) {
        number /= 10;
        cnt++;
    }
    return cnt;
}

const bool isMagical(const int number) {
            while(countDigits(number) > 1) {
                if(abs(number%10 - (number/10)%10) != 2)
                {
                    return false;
                }
                return isMagical(number/10);
            }
            if(countDigits(number) == 1) {return true;}
        return true;
    } 
std::vector<int> output(const int number) {
    std::vector<int> to_be_returned;
    for (size_t i = 0; i < number; i++)
    {
        if(isMagical(i)) {
            to_be_returned.push_back(i);
        }
    }
    return to_be_returned;
}
void printVector(std::vector<int> vec) {
    for (size_t i = 1; i <= vec.size() - 1; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    
}
int main() {
    int number;
    std::cin >> number;
    std::vector<int> array = output(number);
    printVector(array);
}
//1 2 3 4 5 6 7 8 9 13 20 24 31 35 42 46
//1 2 3 4 5 6 7 8 9 13 20 24 31 35 42 46 