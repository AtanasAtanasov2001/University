#include <iostream>

//==========================task1=======================
double findDiagonal(int **matrix, int size, int row, int col)
{
    double sum = 0;
    for (size_t i = 0; i < (size-1) / 2; i++)
    {
        sum += matrix[row + i][col + i];
    }
    
    return sum;
}


// 1 2 0 4 5
// 4 5 0 5 6
// 0 0 0 0 0
// 1 1 0 1 1
// 2 2 0 2 2

// ================================ task 2=======================
bool compareStrings()
{
    int size;
    std::cin >> size;

    char* X;
    X = new char[size];
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> X[i];
        if ( 'a' <= X[i] && X[i] <= 'j')
        {
            std::cout << "The string is correct" << std::endl;
        }
        else 
        {
            std::cout << "The string is incorrect" << std::endl;
            break;
        }
    }
    
    char* N;
    N = new char[size];
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> N[i];
        if ( 0 <= X[i] && X[i] <= 9)
        {
            std::cout << "The string is correct" << std::endl;
        }
        else 
        {
            std::cout << "The string is incorrect" << std::endl;
            break;
        }
    }

    char* new_arr;
    new_arr = new char[size];
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = X[i] - N[i];
    }
    

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if(new_arr[i] != new_arr[j] )   
            {
                return false;
            }    
            else{ return true;}
        }
        
    }
}

//=============================task3=======================
struct Point{
    int x;
    int y;
};

bool valid(int **matrix, size_t size, size_t x, size_t y)
{
    return x >= 0 && x < size && y >= 0 && y < size && matrix[x][y] == 1; 
}
int main()
{
//================================================================
// TASK 1
    // int size;
    // std::cin >> size;
    // std::cout << "The enetered size is: " << size << std::endl;

    // int **matrix = new int *[size];
    // for (size_t i = 0; i < size; i++)
    // {   
    //     matrix[i] = new int[size];
        
    //     for (size_t j = 0; j < size; j++)
    //     {
    //         std::cin >> matrix[i][j];
    //     }
    // }
    // std::cout << std::endl;
    // for (size_t i = 0; i < size; i++)
    // {
    //     for (size_t j = 0; j < size; j++)
    //     {
    //        std::cout << matrix[i][j] << " ";
    //     }
    //    std::cout << std::endl; 
    // }
    
    // int sum1 = findDiagonal(matrix, size , 0, 0);
    // int sum2 = findDiagonal(matrix, size,(size -(size - 1 )/2), 0);
    // int sum3 = findDiagonal(matrix, size, 0,(size -(size - 1 )/2) );
    // int sum4 = findDiagonal(matrix, size, (size -(size - 1 )/2),(size -(size - 1 )/2));

    // std::cout << "Sum1: " << sum1 << std::endl; 
    // std::cout << "Sum2: " << sum2 << std::endl; 
    // std::cout << "Sum3: " << sum3 << std::endl; 
    // std::cout << "Sum4: " << sum4 << std::endl; 

    // if (sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum1)
    // {
    //     std::cout << "The sums are equal, therefore the matrix is correct!!"<< "By condition TRUE"<<std::endl;
    // }
    // else
    // {
    //     std::cout << "The sums are NOT equal, therefore the matrix is NOT correct!!"<<" By condition FALSE" << std::endl;
    // }
    // for (size_t i = 0; i < size; i++)
    // {
    //     delete[] matrix[i];
    // }
    // delete[] matrix;

//============================================================
// TASK 2
    //std::cout << std::boolalpha << compareStrings();

//============================================================
//TASK 3
    size_t size, cnt = 0, emptyPoints = 0, time = 1;
    Point coordinates{};
   std::cout << "Enter size of the matrix:" <<std::endl;
   std::cin >> size;
   std::cout << "Enter coordinates X,Y:" <<std::endl;
   std::cin >> coordinates.x >> coordinates.y;
    
    int **matrix = new int*[size];

    std::cout << "Enter the matrix:" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            emptyPoints++;
        }
        
    }
    std::cout << "======================" << std::endl;
    Point *newPoints = new Point[size * size];
    if(matrix[coordinates.x][coordinates.y] == 1)
    {
        newPoints[cnt++] = coordinates;
    }

    while (cnt != emptyPoints - 1) {
        unsigned temp_counter = cnt;
        for (int i = 0; i < temp_counter; ++i) 
        {
            if (valid(matrix, size, newPoints[i].x - 1, newPoints[i].y)) 
            {
                matrix[newPoints[i].x - 1][newPoints[i].y] = 0;
                Point temp{};
                temp.x = newPoints[i].x - 1;
                temp.y = newPoints[i].y;
                newPoints[cnt++] = temp;
            }
            if (valid(matrix, size,newPoints[i].x + 1, newPoints[i].y)) 
            {
                matrix[newPoints[i].x + 1][newPoints[i].y] = 0;
                Point temp{};
                temp.x = newPoints[i].x + 1;
                temp.y = newPoints[i].y;
                newPoints[cnt++] = temp;
            }
            if (valid(matrix, size, newPoints[i].x,newPoints[i].y - 1)) 
            {
                matrix[newPoints[i].x][newPoints[i].y - 1] = 0;
                Point temp{};
                temp.x = newPoints[i].x;
                temp.y = newPoints[i].y - 1;
                newPoints[cnt++] = temp;
            }
            if (valid(matrix, size, newPoints[i].x, newPoints[i].y + 1)) 
            {
                matrix[newPoints[i].x][newPoints[i].y + 1] = 0;
                Point temp{};
                temp.x = newPoints[i].x;
                temp.y = newPoints[i].y + 1;
                newPoints[cnt++] = temp;
            }
        }
        // for (int i = 0; i < size; ++i) 
        // {
        //     for (int j = 0; j < size; ++j) 
        //     {
        //         std::cout << matrix[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }
        //std::cout << "\n\n";
        if (temp_counter == cnt) 
        {
            std::cout << "Impossible!\n" << cnt;
            break;
        }
        time++;
    }

    std::cout << "Time: " << time;

    for (int i = 0; i < size; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] newPoints;
    
  
    
    
    return 0;
    
}


