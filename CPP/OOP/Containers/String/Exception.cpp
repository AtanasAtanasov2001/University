#include <iostream>
#include "String.h"
#include "String.cpp"

int main()
{
    String s;
    s.push_back('k');
    s.push_back('u');
    s.push_back('r');
    s.pop_back();
    try
    {
        s[-2];
    }
    catch(std::overflow_error& c)
    {
        std::cout << "hello" << std::endl;
    }
    catch(std::out_of_range r)
    {
        std::cout << r.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;   
    }
    std::cout << "end" << std::endl;

    return 0;
}