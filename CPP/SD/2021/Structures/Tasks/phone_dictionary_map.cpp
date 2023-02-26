#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> dictionary;
    for(size_t i = 0; i < n; i++) {
        std::string name;
        int number;
        std::cin >> name >> number;
        dictionary.insert(make_pair(name, number));
    }
    std::string name;
    while(std::cin>>name) {
        std::map<std::string, int>::iterator helper = dictionary.find(name);
        if(helper != dictionary.end()) {
            std::cout << helper->first << "=" << helper->second << "\n";
        } else {
            std::cout << "Not found \n";
        }
    }
    return 0;
}