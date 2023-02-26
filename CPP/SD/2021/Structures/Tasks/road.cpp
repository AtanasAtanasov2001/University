#include <iostream>
#include <string>
#include <vector>
#include <climits>


std::vector<std::pair<std::string, int>> construct_road(const int n ) {
    
    std::vector<std::pair<std::string, int>> to_be_returned;
    
    for (size_t i = 0; i < n; i++)
    {   
        std::string s1;
        int n1;
        std::cin >> s1 >> n1;
        std::pair<std::string, int> to_be_pushed(s1,n1);    
        to_be_returned.push_back(to_be_pushed);
    }

    return to_be_returned;
    
}
void print_road(std::vector<std::pair<std::string, int>> &road) {
    for (size_t i = 0; i < road.size(); i++)
    {
        std::cout << road[i].first << " " << road[i].second << std::endl;
    }
}

std::vector<std::pair<std::string, int>> modify_road(std::vector<std::pair<std::string, int>> road) {
    int size = road.size();
    for (size_t i = 0; i < road.size(); i++)
    {
        if(road[i].first == "green") {
            int value = road[i].second;
            int for_erase = road[i].second;
            int index = i;
            int rocks_value = 0;
            while(value != 0) {
                rocks_value += road[index - 1].second;
                value--;
                index--;
            }
            
           road[i] = std::pair<std::string, int>("white" , rocks_value);
           road.erase(road.begin() + i - for_erase, road.begin() + i);
           i -= for_erase;
        }

        else if(road[i].first == "blue") {
            int value = road[i].second;
            int for_erase = road[i].second;
            int index = i;
            int max_value = INT_MIN;
            while(value != 0) {
                max_value < road[index - 1].second ? max_value = road[index - 1].second : max_value;
                value--;
                index--;
            }
            
           road[i] = std::pair<std::string, int>("white" , max_value);
           road.erase(road.begin() + i - for_erase, road.begin() + i);
           i -= for_erase;
        }
        
    }
    return road;
}
int main() {
    std::vector<std::pair<std::string, int>> new_road = construct_road(7);
    print_road(new_road);
    std::cout << "\n";
    std::vector<std::pair<std::string, int>> modified_road = modify_road(new_road);
    print_road(modified_road);
}