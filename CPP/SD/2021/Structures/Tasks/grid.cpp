#include <iostream>
#include <vector>
#include <string>
#include <queue>

bool isValidPath(std::vector<std::string>& grid, int currentX, int currentY){
    if(!(currentX >= 0 && currentX < grid.size() && currentY >= 0 && currentY < grid[0].size())){
        return false;
    }
    return grid[currentX][currentY] == '.';
}

void setPassed(std::vector<std::string>& grid, int currentX, int currentY){
    grid[currentX][currentY] = 'X';
}

void moveDownward(std::vector<std::string>& grid, int currentX, int currentY,std::queue<std::pair<int,int>>& route){
    if(isValidPath(grid,currentX + 1,currentY)){
        route.push({currentX + 1, currentY});
        moveDownward(grid, currentX + 1, currentY, route);
    }
}

void moveForward(std::vector<std::string>& grid, int currentX, int currentY,std::queue<std::pair<int,int>>& route){
    if(isValidPath(grid,currentX,currentY + 1)){
        route.push({currentX, currentY + 1});
        moveForward(grid, currentX, currentY + 1, route);
    }
}

void moveUpward(std::vector<std::string>& grid, int currentX, int currentY,std::queue<std::pair<int,int>>& route){
    if(isValidPath(grid,currentX - 1,currentY)){
        route.push({currentX - 1, currentY});
        moveUpward(grid, currentX - 1, currentY, route);
    }
}

void moveBackward(std::vector<std::string>& grid, int currentX, int currentY,std::queue<std::pair<int,int>>& route){
    if(isValidPath(grid,currentX,currentY - 1)){
        route.push({currentX, currentY - 1});
        moveBackward(grid, currentX, currentY - 1, route);
    }
}

void findNeighbours(std::vector<std::string>& grid, int currentX, int currentY,std::queue<std::pair<int,int>>& route){
    moveDownward(grid, currentX, currentY, route);
    moveForward(grid, currentX, currentY, route);
    moveUpward(grid, currentX, currentY, route);
    moveBackward(grid, currentX, currentY, route);
}

bool isFinal(int currentX, int currentY, int goalX, int goalY){
    return currentX == goalX && currentY == goalY;
}

int minimumMoves(std::vector<std::string> grid, int startX, int startY, int goalX, int goalY) {
    std::queue<std::pair<int,int>> route;
    route.push({startX,startY});
    int moves = 0;
    while (!route.empty()){
        size_t size = route.size();
        for(int i = 0; i < size; i++){
            findNeighbours(grid,route.front().first,route.front().second,route);
            if(isFinal(route.front().first,route.front().second,goalX,goalY)){
                return moves;
            }
            setPassed(grid,route.front().first,route.front().second);
            route.pop();
        }
        ++moves;
    }
    return -1;
}


int main(){

    std::vector<std::string> grid = {".X.",
                                     ".X.", 
                                     "..."};

    std::cout << minimumMoves(grid,0,0,0,2) << std::endl;  

    std::vector<std::string> grid2 = {"...",
                                      ".X.",
                                      "..."};
    std::cout << minimumMoves(grid2,0,0,1,2) << std::endl;

    return 0;
}