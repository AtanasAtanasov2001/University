#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const size_t MAX_NUMBER_VALUE = 99999 + 1;
const size_t MAX_NUMBER_OF_DIGITS = 5;
const size_t TEN_POWER[MAX_NUMBER_OF_DIGITS] = {1,10,100,1000,10000};

std::vector<bool> visited(MAX_NUMBER_VALUE, false);
std::vector<bool> isAllowedValue(MAX_NUMBER_VALUE, true);

size_t digitUp(size_t digitValue) {
    switch(digitValue) {
        case 9:
            return 0;
    }
    return digitValue + 1;
}

size_t digitDown(size_t digitValue) {
    switch(digitValue) {
        case 9:
            return 0;
    }
    return digitValue - 1;
}

int breadthFirstSearch(size_t initialValue, size_t goalValue) {
    std::queue<size_t> q;
    q.push(initialValue);
    visited[initialValue] = true;

    size_t numberOfItemsInQueue = 1;
    size_t level = 0;

    while (!q.empty()) {
        size_t u = q.front();
        q.pop();

        --numberOfItemsInQueue;
        size_t v, tempValue = u;
        for (size_t i = 0; i != MAX_NUMBER_OF_DIGITS; i++) {
            v = u;
            size_t currentDigitValue = tempValue % 10;
            size_t newNumbersValue[2];

            size_t currentDigitValueUp = digitUp(currentDigitValue);
            size_t currentDigitValueDown = digitDown(currentDigitValue);

            size_t diff = currentDigitValue * TEN_POWER[i];
            v -= diff;

            diff = currentDigitValueUp * TEN_POWER[i];
            v += diff;
            newNumbersValue[0] = v;
            v -= diff;
            diff = currentDigitValueDown * TEN_POWER[i];
            v += diff;
            newNumbersValue[1] = v;

            for (size_t j= 0; j != 2; j++) {
                if(!visited[newNumbersValue[j]] && isAllowedValue[newNumbersValue[j]]) {
                    visited[newNumbersValue[j]] = true;
                    q.push(newNumbersValue[j]);
                    if(newNumbersValue[j] == goalValue) {
                        return level + 1;
                    } 
                }
            }
            
            tempValue / 10;
        }
        if(numberOfItemsInQueue == 0 ) {
            ++level;
            numberOfItemsInQueue = q.size();
        }

    }
    return -1;
    
}
