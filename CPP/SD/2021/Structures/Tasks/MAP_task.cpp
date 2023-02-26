#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    std::map<std::string, int> task_helper;
    int q;
    std::cin >> q;
    for (size_t i = 0; i < q; i++) {
        int command;
        std::cin >> command;
        std::string name;
        std::cin >> name;
        if(command == 1) {
            int points;
            std::cin>> points;
            std::map<std::string, int>::iterator helper = task_helper.find(name);
            if(helper != task_helper.end()) {
                helper->second += points;
            } else {
                task_helper.insert(make_pair(name, points));
            }
        }
        else if (command == 2) {
            task_helper.erase(name);
        }
        else {
            std::map<std::string, int>::iterator helper = task_helper.find(name);
            if(helper != task_helper.end()) {
                std::cout << task_helper.find(name)->second << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        }
    }
    
    return 0;
}