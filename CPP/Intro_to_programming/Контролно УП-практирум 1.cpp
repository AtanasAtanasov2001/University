﻿// Контролно УП-практирум 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const size_t  MAX_SIZE = 256;
 
int main()
{
    // TASK 1
    /*int n, number;

    cin >> n >> number;
    int ConvetedNum = 0;
    int power = 1;

    while(number != 0)
    {
        ConvertedNum += (number%10)*power;
        power *=n;
        number /=10;

    }
    cout << ConvertedNum<<endl;
    return 0;




// TASK 2
    /*char sentence1[MAX_SIZE], sentence2[MAX_SIZE];
    int cnt[26] = { 0 };

    cin.getline(sentence1, MAX_SIZE);
    cin.getline(sentence2, MAX_SIZE);
     
    for (size_t i = 0; sentence1[i] != '\0'; i++)
    {
        if ('a' <= sentence1[i] && sentence1[i] <= 'z')
        {
            cnt[sentence1[i] - 'a']++;
        }
        else if ('A' <= sentence1[i] && sentence1[i] <= 'Z')
        {
            cnt[sentence1[i] - 'A']++;
        }
        else
        {
            continue;
        }
    }
    for (size_t i = 0; sentence2[i] != '\0'; i++)
    {
        if ('a' <= sentence2[i] && sentence2[i] <= 'z')
        {
            cnt[sentence2[i] - 'a']--;
        }
        else if ('A' <= sentence2[i] && sentence2[i] <= 'Z')
        {
            cnt[sentence2[i] - 'A']--;
        }
        else
        {
            continue;
        }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            flag = false;
            break;
        }


    }
    cout << std::boolalpha << flag << endl;*/

    //Task 3
    char name1[MAX_SIZE], char name2[MAX_SIZE], char name3[MAX_SIZE];
    int pen1[5], int pen2[5], int pen3[5],shots[5];

    cin.getline(name1, MAX_SIZE);
    for (int i = 0; i < 5; i++)
    {
        cin >> pen1[i];
    }
   
    cin.getline(name2, MAX_SIZE);
    cin.get();// izchistvame bufera sled 1viya cin.getline;
    for (int i = 0; i < 5; i++)
    {
        cin >> pen2[i];
    }
    
    cin.get()
    cin.getline(name3, MAX_SIZE);
    for (int i = 0; i < 5; i++)
    {
        cin >> pen3[i];
    }

     
    for (int i = 0; i < 5; i++)
    {
        cin >> shots[i];
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (shots[i] == pen1[i])
        {
            cnt1++;
        }
        else if (shots[i] == pen2[i])
        {
            cnt2++;
        }
        else if (shots[i] == pen3[i])
        {
            cnt3++;
        }
    }

    if (cnt1 >= cnt2)
    {
        if (cnt1 >= cnt 3)
        {
            cout << name1 << endl;
        } 
    }
    else if (cnt2 >= cnt 3)
    {
        cout << name2 << endl;
    }
    else 
    {
        cout << name3 << endl;
    }
}
    
   


    
 