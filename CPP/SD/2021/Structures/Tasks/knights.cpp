#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> construct_array(int n) {
    std::vector<int> to_be_returned;
    for (size_t i = 1; i <= n; i++)
    {
        to_be_returned.push_back(i);
    }
    return to_be_returned;
    
}

int knights(int n) {
   std::vector<int> knights_array = construct_array(n);
    int position(0);
    while(knights_array.size() != 1) {
        position = (position + 1) % knights_array.size(); 
        knights_array.erase(knights_array.begin() + position);
        
    }
    return knights_array[0];
}
int main() {
    
    int number;
    std::cin >> number;
    std::cout << knights(number);
    return 0;
}