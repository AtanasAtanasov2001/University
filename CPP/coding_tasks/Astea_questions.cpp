#include <iostream>
#include <string>
#include <algorithm>

//TASK1
bool isSufix(std::string a,std::string b,std::string c) {
    if(c.length() > a.length() && c.length() > b.length()) {return false;}
    else {
        for (size_t j = a.length() - c.length(), i = 0; ((j < a.length()) && (i < c.length())); j++, i++)
        {
            
            if(a[j] != c[i]) {
                return false;
            }
        }
        
            for (size_t j = b.length() - c.length(), i = 0; ((j < b.length()) && (i < c.length())); j++, i++)
            {
                if(b[j] != c[i]) {
                    return false;
                }
            }
        
        return true;
        // a -> abcdef
        // b -> lfkdgjkdef
        // c -> def
    }
}
//TASK2
size_t acekrmanFunction(size_t m, size_t n) {
    if(m==0) {
        return n + 1;
    }
    else if(m > 0 && n == 0) {
        return acekrmanFunction(m-1,1);
    }
    else if(m > 0 && n > 0) {
        return acekrmanFunction(m-1,acekrmanFunction(m,n-1));
    }
}
std::string prettyWord(std::string word) {
    for (size_t i = 0; i < word.length(); i++)
    {
        if( word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 32;
        }
    }
    std::sort(word.begin(), word.end());
    return word;
}
int main() {


// Task1:
//     std::string a = "abcdef";
//     std::string b = "lfkdgjkdef";
//     std::string c = "def";
//     std::cout << std::boolalpha << isSufix(a,b,c);
// Task2: 
//std::cout << acekrmanFunction(3,1);
// Task3
std::cout << prettyWord("BcdA");
    return 0;
}