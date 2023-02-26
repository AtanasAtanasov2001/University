#include "task4.h"

template <typename T>
void Spreadsheet<T>::set(unsigned long row, char col, const T& value){
    for (unsigned long i = 0; i < get_rows().size(); i++)
    {
        for (size_t j = 0; j < get_cols().size(); j++)
        {
            if(row == i && col == j){
                this->values[i][j] = value;
            }
        }
    }
}

template <typename T>
T Spreadsheet<T>::get(unsigned long row, char col){
    return this->values[row][col];
}

template <typename T>
T Spreadsheet<T>::max(){
    T biggest = this->get_values()[0]['A'];
    for (unsigned long i = 0; i < this->get_rows().size(); i++)
    {
        for (size_t j = 0; j < this->get_cols().size(); j++)
        {
            if(get_values()[i][j] > biggest){
                biggest = this->get_values()[i][j];
            }
        }
        
    }
    return biggest;
}

int main(){
    Spreadsheet<int> t;
    t.set(0,'B',7);
    std::cout << t.get(0,'B');
    return 0;
}