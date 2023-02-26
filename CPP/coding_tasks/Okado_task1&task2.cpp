    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <stack>

//from vector -> maximum 1-digit number
//size [1,1000]
//number [-10000,10000]
int solution(std::vector<int> &A) {
    int maximumOneDigit = 0;
    // write your code in C++14 (g++ 6.2.0)
    for (int i = 0; i < A.size(); i++) {
        if(A[i]/10 == 0  && A[i] > maximumOneDigit) {  
        maximumOneDigit = A[i];
        } else {
            continue;
        }
    }
    if(maximumOneDigit != 0) {
        return maximumOneDigit;
    } else {
        return 1;
    }
}

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//string -> commands -> work with stack
//POP -> stack.pop;
//DUB -> stack.push(stack.top());
//"-" -> stack(top) - stack(top-1);
//"+" -> stack(top) + stack(top-1);
//int -> push;
//return stack.top
int solutionTwo(std::string &S) {
    std::stack<int> stack;
    if(S.size() > 2000) {
        std::cout << "The length of the string is above 2000! \n";
        return -1;
    } else {
        for (size_t i = 0; i < S.size(); i++) {
            if((S[i] > 'a' && S[i] < 'z' )|| (S[i] > 'A' && S[i] < 'Z' )) {
                std::string substr = S.substr(i,S.find(" "));
                i += substr.length();
                if(substr == "POP") {
                    stack.pop();
                } 
                else if(substr == "DUB") {
                    stack.push(stack.top());
                }
                else {
                    continue;
                }
                
            }
            // else if((S[i] > 'a' && S[i] < 'z' )|| (S[i] > 'A' && S[i] < 'Z' )) {
            //     std::string substr = S.substr(i,S.find(" "));
            //     i += substr.length();
            //     if(substr == "DUB") {
            //         stack.push(stack.top());
            //     } else {
            //         continue;
            //     }
                
            // }
            else if(S[i] == '-') {
                if(stack.size() < 2) {
                    std::cout << "Not enough elements in the stack! \n";
                    return -1;
                } else {
                    int helperIntOne = stack.top();
                    stack.pop();
                    int helperIntTwo = stack.top();
                    stack.pop();

                    if(helperIntOne - helperIntTwo < 0) {
                        return -1;
                    } else {
                        stack.push(helperIntOne-helperIntTwo);
                    }
                }
                    
            } 
            else if(S[i] == '+') {
                
                if(stack.size() < 2) {
                    std::cout << "Not enough elements in the stack! \n";
                    return -1;
                }
                int helperIntOne = stack.top();
                stack.pop();
                int helperIntTwo = stack.top();
                stack.pop();

                stack.push(helperIntOne+helperIntTwo);
            }
            else if(std::isdigit(S[i])) {
                std::string substr = S.substr(i,S.find(" "));
                i += substr.length();
                stack.push(std::stoi(substr));
            }
        }
    }
    return stack.top();
}
    // write your code in C++14 (g++ 6.2.0)


int main() {
    //TASK1
    // int size;
    // std::cout << "Enter the size of the vector: ";
    // // std::cin >> size;
    // std::vector<int> A = {90, -91, 1011, -100, 84, 66, 99, 1, 99};
    // for (size_t i = 0; i < A.size(); i++)
    //     {
    //         if(A[i] < -10000 || A[i] > 10000) {
    //             std::cout << "The element is not in the range [-10000,10000] \n";
    //             return 0;
    //         } else {
    //             continue;
    //         }
            
    //     }
    // std::cout << "The maximum among all one-digit numbers is: " <<solution(A);

    //TASK2
    std::string C = "13 DUP 4 POP 5 DUP + DUP + -"; // return 8
   // 4 8 -> 8
    std::cout << solutionTwo(C);
    
    
    return 0;
}