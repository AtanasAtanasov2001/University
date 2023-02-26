#include <iostream>
#include <list>
#include <vector>
template <typename T>
class Spreadsheet
{   
    protected:
    std::vector<unsigned long> rows;
    std::vector<char> cols;
    T** values;

    public:
    Spreadsheet(){
        for (size_t i = 0; i < 4294967295 ; i++)
        {
            rows[i] = i;
        }
        //
        for (char i = 'A'; i < 26; i++)
        {
            cols[i] = i;
        }
        this->values = new T[1000][26];
        for (size_t i = 0; i < rows.size(); i++)
        {
            for (size_t j = 0; j < cols.size(); j++)
            {
                values[i][j] = 0;
            }
            
        }
        
        
    }
    std::vector<unsigned long> get_rows() {return this->rows;}
    std::vector<char> get_cols() {return this->cols;}
    T** get_values(){return this->values;}
    void set(unsigned long row, char col, const T& value);
    T get(unsigned long row, char col);
    T max();
};