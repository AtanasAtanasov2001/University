#include <iostream>
#include <functional>
#include <vector>
 std::vector<double> filter(std::vector<double>& sal, std::function<bool(double)> filterFunction)
{
    std::vector<double> filtered;
    for(int i = 0; i < sal.size(); i++)
    {
        if(filterFunction(sal[i]))
        {
            filtered.push_back(sal[i]);
        }
    }

    return filtered;
}