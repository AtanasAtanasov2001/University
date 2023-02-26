#include <iostream>
#include <algorithm>

const size_t MAX_N = 100;

struct Date {
    char day;
    char month;
    size_t year;
    size_t index;

    bool operator< (const Date& other ) const {
        if( year == other.year) {
            if( month == other.month) {
                return day < other.day;           
            }
            return month < other.month;
        }
        return year < other.year;

    } 
};  

Date dates[MAX_N];

int main() {
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i != n; i++) {
        size_t day, month, year;
        std::cin >> day >> month >> year;
        dates[i].day = (char)day;
        dates[i].month = (char)month;
        dates[i].year = year;
        dates[i].index = i + 1;
    }
    std::stable_sort(dates, dates + n);

    for (size_t i = 0; i != n; i++)
    {
        std::cout << dates[i].index;
    }
    
    
}
