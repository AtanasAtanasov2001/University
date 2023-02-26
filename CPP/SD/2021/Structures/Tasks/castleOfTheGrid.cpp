#include <iostream>
#include <stack>
#include <queue>


struct Node {
    int X;
    int Y;
    Node* next;
    Node() = default;
    Node(int X_, int Y_, Node* next_ = nullptr) : X(X_), Y(Y_),next(next_) {}
    Node& operator=( Node* other) {
        if(this != other) {
            this->X = other->X;
            this->Y = other->Y;
            this->next = other->next;
        }
        return *this;
    }
    bool operator==(const Node& other) {        
        return  (this->X == other.X) && (this->Y == other.Y )&&  (this->next == other.next);
    }
};
char** construct_grit(const int rows, const int cols) {
    char** matrix = new char*[rows];
    char value;
    
    for (size_t i = 0; i < rows; i++)
    {
        
        matrix [i] = new char[cols];
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> value;
            matrix[i][j] = value;
        }
    }
    return matrix;
}
Node** construct_predecessor_matrix(const int rows, const int cols) {
    Node** matrix = new Node*[rows];
    
    for (size_t i = 0; i < rows; i++)
    {
        matrix [i] = new Node[cols];
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = Node();
        }
    }
    return matrix;
}
char** construct_color_matrix(const int rows, const int cols) {
    char** c_matrix = new char*[rows]; 
    for (size_t i = 0; i < rows; i++)
    {
        c_matrix[i] = new char[cols];
        for (size_t j = 0; j < cols; j++)
        {
            c_matrix[i][j] = 'W';
        }
    }
    return c_matrix;
}


void neighbours(int grit_size,Node* start,std::queue<Node*> nodes,char** grit, char** color_matrix,Node** predecessor_matrix) {
    Node* current = start;

   for (size_t i = 0; i < grit_size; i++)
   {
       std::cout << "vleznah 1 for neighbours" << "\n";
       if(grit[i][current->X] != 'X') {
            Node* to_be_pushed = new Node(i, current->X);
            if(color_matrix[i][current->X] == 'W') {
                nodes.push(to_be_pushed);
                color_matrix[i][current->X] = 'G';
                predecessor_matrix[i][current->X] = current;
            } else {
                continue;
            }
        } 
   }
   for (size_t i = 0; i < grit_size; i++)
   {
       std::cout << "vleznah 2 for neighbours" << "\n";
       if(grit[current->Y][i] != 'X') {
            Node* to_be_pushed = new Node(current->Y,i);
            if(color_matrix[current->Y][i] == 'W') {
                nodes.push(to_be_pushed);
                color_matrix[current->Y][i] = 'G';
                predecessor_matrix[current->Y][i] = current;
            } else {
                continue;
            }
        }      
   }

}

//. . . .
//. . . X
//X . . .
//. . . .
int BFS_Grit(int grit_size,Node *start, Node *destination) {
    std::queue<Node*> nodes;
    char** grit = construct_grit(grit_size,grit_size);
    char** color_matrix = construct_color_matrix(grit_size,grit_size);
    Node** predecessor_matrix = construct_predecessor_matrix(grit_size,grit_size);
    Node* current = start;
    neighbours(grit_size, current,nodes,grit,color_matrix,predecessor_matrix);


    for (size_t i = 0; i < grit_size; i++)
    {
       for (size_t j = 0; j < grit_size; j++)
       {
           std::cout << "vleznah 1 dvoen for" << "\n";
           nodes.pop();
           current->next = nodes.front();
           color_matrix[i][j] = 'R';
           current = current->next;
           neighbours(grit_size,current,nodes,grit ,color_matrix,predecessor_matrix);
       }
    }

    std::stack<Node*> predecessor_stack;
    Node* temp = new Node (destination->X, destination->Y);
    while (predecessor_stack.top()->X != start->X && predecessor_stack.top()->Y != start->Y)
    {
        std::cout << "vleznah 1 while" << "\n";
        predecessor_stack.push(temp);
        temp = &predecessor_matrix[temp->X][temp->Y];
    }
    int counter = 0;
    while (!predecessor_stack.empty())
    {
        std::cout << "vleznah 24 while" << "\n";
        predecessor_stack.pop();
        counter++;
    }
    return counter-1;
    
        
}

void print_matrix(char **matrix, int rows, int cols) {
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j= 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " " ;
        }
        std::cout << "\n";
    }
}
int main() {
    int grit_size;
    std::cout << "Enter the size of the grit: ";
    std::cin >> grit_size;
    // char** grit = construct_grit(grit_size,grit_size);
    // print_matrix(grit,grit_size,grit_size);
    Node* start= new Node (0,0);
    Node* destination = new Node(3,3);
    BFS_Grit(grit_size,start,destination );
}