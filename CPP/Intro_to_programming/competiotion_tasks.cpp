#include <iostream>
#include <limits.h>

int trip()
{
    int n,m;
    std::cout << "Enter the length of the road: "<<std::endl;
    std::cin >>n;
    std::cout << "Enter the length of the section of the road that can be passed the fastest: "<<std::endl;
    std::cin >>m;

    int *time;
    time = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> time[i];
    }
    int index = 0;
    int sum = INT_MAX;
    for (size_t i = 0; i < (n - m) + 1; i++)
    {
        int new_sum = time[i] + time[i + 1] + time[i + 2];
        
        if (sum >= new_sum)
        {
           index = i; 
           sum = new_sum;
        }     
    }
    
    for (size_t i = 0; i < n; i++)
    {
        std::cout << time[i] << " ";
    }
    std::cout << std::endl;
    delete[] time;
    return index;

}
//6 5 4 4 6 3
int main()
{
    std::cout << trip();
    return 0;
}