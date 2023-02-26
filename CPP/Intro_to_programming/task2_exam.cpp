#include<iostream>

int UpCount(char** matrix, size_t row_symbols,size_t col_symbols)
{
    int upCount = 0;
    for (size_t i = 0; i < row_symbols - 1; i++)
    {
        for (size_t j = 0; j < col_symbols - 1; j++)
        {
            if( (matrix[i][j] == 'u' && matrix[i][j + 1] == 'p') || (matrix[i][j] == 'u' && matrix[i+1][j+1] == 'p') )
            {
                upCount++;
            }
        }
        
    }
    return upCount;
    
}
int main()
{
    int row_symbols, col_symbols;
    std::cin >> row_symbols >> col_symbols;
    char** matrix = new char* [row_symbols];
    for (size_t i = 0; i < row_symbols; i++)
    {
        matrix[i] = new char[col_symbols];
        for (size_t j = 0; j < col_symbols; j++)
        {
            std::cin >> matrix[i][j];
        }
        
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < row_symbols; i++)
    {
        for (size_t j = 0; j < col_symbols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << UpCount(matrix,row_symbols, col_symbols);

    for (size_t i = 0; i < row_symbols; i++)
    {
        delete[] matrix[i];
        for (size_t j = 0; j < col_symbols; j++)
        {
            delete[] matrix[j];
        }
        
    }
    delete[] matrix;
}