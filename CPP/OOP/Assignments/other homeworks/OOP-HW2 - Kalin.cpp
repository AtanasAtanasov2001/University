#include <iostream>
template <typename T>
void inputArray(T* array, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "a [" << i << "]"<< std::endl;
        std::cin >> array[i];
    }
    
}
template <typename T>
void print(T * arr,int size)
{
    for (size_t i = 0; i < size; i++)
    {
    std::cout << arr[i];
    }
}
template <typename T>
bool ordered (T* array, int n)
{
    for (size_t i = 0; i < n ; i++)
    {
       if(!(array[i] < array[i+1]))
       {
           return false;
       }
       return true;
    }
    
}

template <typename T> 
bool member(T*array, int n, T x)
{
    for (size_t i = 0; i < n; i++)
    {
        if(array[i] == x)
        {
            return true;
        }
    }
    return false;
    
}
struct S
{
    int a;
    int b;
    int c;
};
using compareFunc = bool (*) (S,S);

bool comapreA (S str1, S str2)
{
    return str1.a <= str2.a;
}
bool comapreB (S str1, S str2)
{
    return str1.b <= str2.b;
}
bool comapreLexi (S str1, S str2)
{
    return 100*str1.a + 10*str1.b + str1.c < 100*str2.a + 10*str2.b + str2.c;
}

compareFunc cpA = comapreA;
compareFunc cpB = comapreB;
compareFunc cpL = comapreLexi;

template <typename T>
    void sort (T* array, int n,compareFunc f)
     {
         bool flag = true;
         while (flag)
         {
            flag = false;
            for (size_t i = 0; i < n; i++)
            {
                if (!(f(array[i],array[i+1])))
                {
                    S temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    flag = true;
                }
            }
         }
     }
using doubleFunc = double (*) (double);

double increaseByOne(double n)
{
    return ++n;
}
class Time
{
    public:
    Time(unsigned int hours_,unsigned int minutes_) : hours(hours_), minutes(minutes_)
        , currentMoment(hours_ < 12 ? "Sutrin" : ((hours_ <= 19) ? "Obed" : ((hours_ < 24) ? "Vecher" : "" )) )
    {
        checkCorrect(hours_, minutes_);      
    }
    
    void checkCorrect(unsigned int hours, unsigned int minutes)
    {
        if(!(hours >= 0 && hours <= 24) || (!(minutes >= 0 && minutes <= 60 ) ))
        {
            std::cout << "Nasko pak si piyan"<< std::endl;
        }
    }
    
    void addMinutes(int number)
    {
        minutes = minutes + number;
        // minutes/60 = 0 => hours...minutes/60 != 0 =>...hours + ostatuk
        hours += minutes / 60;
        minutes = minutes % 60;
        hours = hours % 24;
    }

    unsigned int minutesElapsed()
    {
        int elapsed = hours * 60 + minutes;
        return elapsed;
    }

    bool operator <(Time other)
    {
        return (minutesElapsed() < other.minutesElapsed());
    }

    Time operator +(Time other)
    {
        int curr =  minutesElapsed() + other.minutesElapsed();
        int hrs = (curr / 60) % 24;
        int mnts = curr % 60;
        Time res(hrs,mnts);
        return res;
    }

    Time operator *(int n)
    {
        int curr = minutesElapsed() * n;
        int hrs = (curr / 60) % 24;
        int mnts = curr % 60;
        Time res(hrs,mnts);
        return res;
    }


    
    void print()
    {
        std::cout << hours << ":" << minutes << std::endl;
    }
    private:
    
    unsigned int hours;
    unsigned int minutes;
    const char *currentMoment;
};
// box1.a -- bo2.a-- box5.a---

Time operator *(int n, Time other)
{
    int curr =  n * other.minutesElapsed();
    int hrs = (curr / 60) % 24;
    int mnts = curr % 60;
    Time res(hrs,mnts);
    return res;
}
struct Point
{
    int x;
    int y;
    int z;
};

//l1 || l2 <=> (l1x1 - l1x2 == l2x1 - l2x2) && (l1y1 - l1y2 == l2y1 - l2y2) && (l1z1 - l1z2 == l2z1 - l2z2)
//t1(x1,y1,z1)     t2(x2,y2,z2)
//t1'(x1',y1',z1') t2'(x2',y2',z2')
class Line
{
    public:
    Line(Point fst_,Point snd_) : fst(fst_), snd(snd_)
    {}
    bool operator || (Line other)
    {
        return( ((snd.y-fst.y) == 0 ? 0 : (snd.z-fst.z)/(snd.y-fst.y)) == ((other.snd.y-other.fst.y) == 0 ? 0 : (other.snd.z-other.fst.z)/(other.snd.y-other.fst.y)) &&  
                ((snd.y-fst.y) == 0 ? 0 : (snd.x-fst.x)/(snd.y-fst.y)) == ((other.snd.y-other.fst.y) == 0 ? 0 : (other.snd.x-other.fst.x)/(other.snd.y-other.fst.y)) &&
                ((snd.x-fst.x) == 0 ? 0 : (snd.z-fst.z)/(snd.x-fst.x)) == ((other.snd.x-other.fst.x) == 0 ? 0 : (other.snd.z-other.fst.z)/(other.snd.x-other.fst.x)) );
    }
    bool isInLine(Point other)
    {

    }
    private:
    Point fst;
    Point snd;
};
// 4 * (1,20) = 
int main()
{
// Task 1
//     double array[3];
//    inputArray(array,3);
//    std::cout << ordered(array,3)<<std::endl;
//    std::cout << member<double>(array, 3,2)<<std::endl;
//     print (array,3);
//--------------------------
// Task - Complicated funcs
// doubleFunc functions[5];
// functions[0] = increaseByOne;
// std::cout << functions[0](25);

// S array[3] = {{15,7,4},{2,5,10},{1,60,3}};
// sort(array,3,cpL);
// std::cout << array[0].b <<","<< array[1].b <<","<< array[2].b << std::endl;
//--------------------------------------------
//Tasks - Classes

//Time den(1,20); // 1324
//Time den2(16,30);// 990

//(4 * den).print();
// std::cout << std::boolalpha  << (den < den2);
// den.addMinutes(50);
// std::cout << den.minutesElapsed() << std::endl;
// std::cout << den.currentMoment << " " << den.hours << " "<< den.minutes << std::endl;

Line line1({0,0,0},{2,2,0});
Line line2({1,3,0},{5,8,0});
std::cout << std::boolalpha  << (line1 || line2);
}
