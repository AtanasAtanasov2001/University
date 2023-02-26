#include <iostream>
#include <string>


const bool equalBrackets(const std::string bracketsSet ) {
   std::string openingBrackets;
   std::string closingBrackets;
   for (size_t i = 0; i < bracketsSet.size(); i++)
   {
       if(bracketsSet[i] == '[' || bracketsSet[i] == '{' || bracketsSet[i] == '(') {
           openingBrackets.push_back(bracketsSet[i]);
           continue;
       }
       else if(bracketsSet[i] == ']' || bracketsSet[i] == '}' || bracketsSet[i] == ')') {
           closingBrackets.push_back(bracketsSet[i]);
           continue;
       }
   }
   if(openingBrackets.size() == closingBrackets.size()) {
       return true;
   } else { 
       return false;
    }
   
}

int main() {

    std::string s1 = {"[()]{​​}​​{​​[()()]()"};
    std::string s2 = {"[()]{​​}​​{​​[()()]()}​​"};
    std::cout << equalBrackets(s2);
    return 0;
}
// [()]{​​}​​{​​[()()]() - не
// [()]{​​}​​{​​[()()]()}​​ - да
