#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#pragma once

class BigNumber {
    
    private:
    std::vector<char> number;
 
    public:
    BigNumber() {
        this->number.push_back('0');
    }
 
    BigNumber(std::vector<char> num) : number(num) {}
 
    BigNumber(std::string num) {
        std::vector<char> vec;
        for (int i = 0; i < num.size(); i++) {
            vec.push_back(num[i]);
        }
        this->number = vec;
    }
 
    BigNumber& operator=(BigNumber& otherNumber){
        if(this != &otherNumber){
            this->number = otherNumber.getNumber();
        } else {
            throw std::bad_alloc();
        }
        return *this;
    }
 
 
    friend std::ostream& operator<<(std::ostream& out, const BigNumber& num);
 
    std::vector<char>& getNumber() {
        return this->number;
    }
 
    std::string toHex() {
        std::string res;
        BigNumber current = *this;
        BigNumber base("16");
        BigNumber zero("0");
 
 
        while (current > zero) {
            std::pair<BigNumber&, BigNumber&> p = current / base;
            current = p.first;
 
            if (p.second.getNumber().size() == 1) {
                res.push_back(p.second.getNumber()[0]);
            } else {
                switch (p.second.getNumber()[1]) {
                case '1':
                    res.push_back('B');
                    break;
                case '2':
                    res.push_back('C');
                    break;
                case '3':
                    res.push_back('D');
                    break;
                case '4':
                    res.push_back('E');
                    break;
                case '5':
                    res.push_back('F');
                    break;
                case '0':
                    res.push_back('A');
                    break;
                default:
                    break;
                }
            }
        }
 
        std::reverse(res.begin(), res.end());
        return res;
    }
 
    bool operator>(BigNumber& otherNumber) {
        if(this->getNumber().size() > otherNumber.getNumber().size()) return true;
        if(this->getNumber().size() < otherNumber.getNumber().size()) return false;
        for (size_t i = 0; i < this->getNumber().size(); i++)
        {
            if(this->getNumber()[i] > otherNumber.getNumber()[i]) return true;
            if(this->getNumber()[i] < otherNumber.getNumber()[i]) return false;
        }
        return false;
    }
 
    bool operator<(BigNumber& otherNumber) {
        if(this->getNumber().size() < otherNumber.getNumber().size()) return true;
        if(this->getNumber().size() > otherNumber.getNumber().size()) return false;
        for (size_t i = 0; i < this->getNumber().size(); i++)
        {
            if(this->getNumber()[i] < otherNumber.getNumber()[i]) return true;
            if(this->getNumber()[i] > otherNumber.getNumber()[i]) return false;
        }
        return false;
    }
 
    bool operator==(BigNumber& otherNumber) {
        if(*this < otherNumber) return false;
        if(*this > otherNumber) return false;
        return true;
    }
 
    BigNumber& operator+(BigNumber& otherNumber){
        std::vector<char> helper;
        int i = this->number.size() - 1;
        int j = otherNumber.getNumber().size() - 1;
        int toAdd = 0;
 
        while(i >= 0 || j >= 0) {
            int left = i >= 0 ? this->number[i--] - '0' : 0;
            int right = j >= 0 ? otherNumber.getNumber()[j--] - '0' : 0;
 
            toAdd += left + right;
 
            helper.push_back(toAdd%10 + '0');
            toAdd = toAdd/10;
        }
        if (toAdd != 0) helper.push_back(toAdd + '0');
 
        std::reverse(helper.begin(), helper.end());
 
        BigNumber* toReturn = new BigNumber(helper);
        return *toReturn;
    }
 
    BigNumber& operator-(BigNumber& otherNumber){
        std::vector<char> helper;
        int i = this->number.size() - 1;
        int j = otherNumber.number.size() - 1;
        int toAdd = 0;
 
        while(i >= 0 || j >= 0) {
            int left = i >= 0 ? this->number[i--] - '0' + toAdd : 0;
            int right = j >= 0 ? otherNumber.getNumber()[j--] - '0' : 0;
 
            if(left < right) {
                left += 10;
                toAdd = -1;
            } else toAdd = 0;
 
            helper.push_back((left - right) + '0');
        }
 
        for (size_t i = helper.size()-1; i >= 0; i--)
        {
            if (helper[i] == '0') {
                helper.pop_back();
            } else break;
 
        }
 
        std::reverse(helper.begin(), helper.end());
 
 
        BigNumber* toReturn = new BigNumber(helper);
        return *toReturn;
    }
 
    BigNumber& operator*(BigNumber& otherNumber){
        if(otherNumber.getNumber()[0] == '0' || this->getNumber()[0] == '0'){
            return *(new BigNumber());
        }
        int i = this->number.size() - 1;
        int numbers_counter = 0;
        std::vector<BigNumber> bigNums;
 
        while(i >= 0) {
            int left = i >= 0 ? this->number[i--] - '0' : 0;
            std::vector<char> right = otherNumber.getNumber();
 
            int j = otherNumber.getNumber().size() - 1;
            int toAdd = 0;
 
            std::vector<char> helper;
            for (size_t ctr = 0; ctr < numbers_counter; ctr++) {
                helper.push_back(0 + '0');
            }
 
            while(j >= 0){
                toAdd += left * ( right[j--] - '0' );
                helper.push_back(toAdd%10 + '0');
                toAdd = toAdd/10;
            }
 
            if (toAdd != 0) helper.push_back(toAdd + '0');
            std::reverse(helper.begin(), helper.end());
 
            BigNumber newNum(helper);
            bigNums.push_back(newNum);
            numbers_counter++;
        }
 
        BigNumber *toReturn = new BigNumber;
        for (size_t i = 0; i <  bigNums.size(); i++) {
            *toReturn = *toReturn + bigNums[i];
        }
 
        return *toReturn;
    }
 
    
    std::pair<BigNumber&, BigNumber&> operator/(BigNumber& otherNumber){
        if(this->getNumber()[0] == '0') return (std::pair<BigNumber&, BigNumber&>{*(new BigNumber),*(new BigNumber)});
        if(otherNumber.getNumber()[0] == '0')  throw std::overflow_error("Divide by zero exception");

        BigNumber *toReturn = new BigNumber;
        toReturn->getNumber().clear();

        BigNumber current;
        current.getNumber().clear();
        bool flag = false;
        bool isStart = true;

        for (int i = 0; i < this->getNumber().size(); i++) {

            if(current < otherNumber) {
                current.getNumber().push_back(this->getNumber()[i]);
                if (flag && !isStart) toReturn->getNumber().push_back('0');
                if(current < otherNumber) {
                    flag = true;
                    continue;
                }
            }
            flag = false;

            for (size_t counter = 1; counter <= 10; counter++) {
                std::vector<char> multiplier_vector;
                multiplier_vector.push_back(counter + '0');
                BigNumber multiplier(multiplier_vector);

                if((otherNumber * multiplier) > current) {
                    multiplier.getNumber()[0] = (counter-1) + '0';

                    current = current - (otherNumber * multiplier);
                    toReturn->getNumber().push_back(counter-1 + '0');
                    isStart = false;
                    break;
                }
            }
        }

        if (toReturn->getNumber().size() == 0) toReturn = new BigNumber;
        if (current.getNumber().size() == 0) current = *(new BigNumber);

        if (!((*toReturn) * otherNumber + current == *this)) {
            toReturn->getNumber().push_back('0');
        }


        return std::pair<BigNumber&, BigNumber&> {*toReturn, *(new BigNumber(current))};
    }
 
    BigNumber& SQRT(){
        int power = (this->getNumber().size())/2;
 
        BigNumber* guess = new BigNumber("1");
        BigNumber ten("10");
        BigNumber two("2");
 
        for (size_t i = 0; i < power; i++) {
            *guess = *guess * ten;
        }
 
        BigNumber curr;
        while (true)
        {
            curr = (((*guess) + ((*this)/(*guess)).first)/two).first;
            if(curr == *guess) break;
            *guess = curr;
        }
 
        return *guess;
    }
};
 
std::ostream& operator<<(std::ostream& out, std::pair<BigNumber&, BigNumber&> division) {
    for (size_t i = 0; i < division.first.getNumber().size(); i++)
    {
        out << division.first.getNumber()[i];
    }
    out << " (";
    for (size_t i = 0; i < division.second.getNumber().size(); i++)
    {
        out << division.second.getNumber()[i];
    }
    out << ")";
 
    out << '\0';
    return out;
}
 
std::ostream& operator<<(std::ostream& out, const BigNumber& num) {
    for (size_t i = 0; i < num.number.size(); i++)
    {
        out << num.number[i];
    }
    out << '\0';
    return out;
}