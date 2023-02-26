#include<iostream>

class Matrix
{
public:
    unsigned int rows;
    unsigned int columns;
    int **data;
    
    void copy(const Matrix& other);

    friend std::ostream& operator<< (std::ostream& out, const Matrix& item);
    friend std::istream& operator>> (std::istream& in, Matrix& item);

    bool operator==(const Matrix& other) const;
    Matrix operator+(const Matrix& other);
// r c - data
    Matrix(unsigned int r,unsigned int c,int **data_):rows(r), columns(c)
   {
       for (size_t i = 0; i < rows; i++)
        {
            if (data_[i] != nullptr)
            {
                data[i] = new int [rows]; 
                for (size_t j = 0; j < columns; j++)
                {
                    data[i][j] = data_[i][j];
                }
                
            }
            else
            {
                std::cout << "Wrong input" << std::endl;
            } 
        }
    }
    Matrix()
    {
        rows = 0;
        columns = 0;
        *data = nullptr;
    }
    ~Matrix()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
        
    }

   Matrix operator=(const Matrix& other)
   {
       if (this->data != nullptr)
       {
           delete[] this->data;
           this->data = nullptr;
       }
       this->copy(other);
       return *this;
    }
    //idk if that's correct but if it's not it's the same as copy const!!!
   Matrix(const Matrix& other)
   {
       this->copy(other);
   }
  
};
void Matrix::copy(const Matrix& other)
{
    this->rows = other.rows;
    this->columns = other.columns;

    this->data = new int*[rows];
    for (size_t i = 0; i < other.rows; i++)
    {
        this->data[i] = new int[columns];
       for (size_t j = 0; j < other.columns; j++)
       {
           data[i][j] = other.data[i][j];
       }
    }
}
std::ostream& operator<<(std::ostream& out, const Matrix& other)
{
    out << "Rows "<< other.rows <<" "<< "Columns " << other.columns <<std::endl;
    for (size_t i = 0; i < other.rows; i++)
    {
        for (size_t j = 0; j < other.columns; j++)
        {
            out << other.data[i][j] << " "; 
        }
        out << std::endl;
    }
    
    return out;
}
std::istream& operator>>(std::istream& in, Matrix& other)
{
    in >> other.rows >> other.columns;
    other.data = new int*[other.rows];
    for (int i = 0; i < other.rows; i++)
    {
        other.data[i] = new int[other.columns];
        for (int j = 0; j < other.columns; j++)
        {
            in >> other.data[i][j] ;
        }
    }

    return in;
}

bool Matrix::operator==(const Matrix& other) const 
{
    return ((rows * columns) == (other.rows * other.columns));
}

Matrix Matrix::operator+(const Matrix& other) 
{
    Matrix result;
    result.rows = rows;
    result.columns = columns;
    result.data = new int*[rows];
    for (size_t i = 0; i < other.rows; i++)
    {
        result.data[i] = new int[columns];
       for (size_t j = 0; j < other.columns; j++)
       {
           result.data[i][j] = other.data[i][j] + data[i][j];
       }
       
    }
    return (result);
}
int main()
{
    int **data = new int*[3];
    data[0] = new int[3]{1,2,3};
    data[1] = new int[3]{4,5,6};
    data[2] = new int[3]{7,8,9};
    Matrix m1(3,3,data);


    Matrix m2;
    std::cin >> m2;
    std::cout << m2 <<std::endl;
}

