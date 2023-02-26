#include <iostream>
const size_t maxPower = 50;

struct Poly
{
    double coefs[maxPower];
    int power;
    // a*x^n
    // (a*x^n + b*x^k....+ const)' = (a*n*x^n-1 + b*k*x^k-1 +....0)
    void diff()
    {
        for (size_t i = 0; i <= power; i++)
        {
          coefs[i] *= power - i;
        }

        if(power > 0)
        {
            power -= 1;
        }
  
    }

}; 

Poly diff_two(Poly fmi)
{
    for (size_t i = 0; i <= fmi.power; i++)
    {
        fmi.coefs[i] *= fmi.power - i;
    }

    if(fmi.power > 0)
    {
        fmi.power -= 1;
    }

    return fmi;    
}

Poly result(Poly a, Poly b)
{
    Poly result;

    //int k = 0;
    //int coefs[maxPower];
    // for (int i = 0; i <= a.power; i++)
    // {
    //     // 0 * 0 && *1
    //     // 1 * 0 && *1
    //     //00 01
    //     //10 11
    //     for (int j = 0; j <= b.power; j++)
    //     {
    //         coefs[k] = a.coefs[i] * b.coefs[j];
    //         k++;
    //     }
    // }
    result.power = a.power + b.power;
    for (int i = 0; i <= result.power; i++)
    {
        result.coefs[i] = 0;
    }    
    for (int i = 0; i <= a.power; i++)
    {
        for (int j = 0; j <= b.power; j++)
        {
            result.coefs[i+j] += a.coefs[i] * b.coefs[j];
            //std::cout << a.coefs[i] * b.coefs[j]<<std::endl;
        }
    }
    
   
return result;
    
}
//3x^2 + 5x + 2
//2x + 4
//
//3*2 + 3*4 + 3*3 + 5*2 + 5*4 + 5*3 + 2*2 + 2*4 + 2*3
// 4     3     2     3     2     1     2     1     0
//
// res.coefs[i+j] += a.coefs[i] * b.coefs[j] 
// i=0 ; j=1 - 3.. i=1 ; j=0 - 3
//
// i=0 ; j=2 - 2.... i=1 ; j=1 - 2...i=2 ; j=0 - 2

//[0, 1, 2, 3, 4]
//[0, 0, 0, 0, 0]
//0+0 = 0
//0+1 1+0 = 1 
//0+2 1+1 2+0 = 2
//1+2 2+1 = 3
//2+2 = 4
struct Product
{
    char description[32];
    int partNum;
    double cost;

    void Print()
    {
        std::cout << "description: " << description << std::endl;
        std::cout << "partNum: " << partNum << std::endl;
        std::cout << "cost: " << cost << std::endl;
    }
};

struct Point
{
    int x,y;
};


void Sort(Point *array, int size)
{
    bool change = true;
    while (change)
    { 
        change = false;
        for (int i = 0; i < size ; i++)
        {
           if(array[i].x*10 +array[i].y  > array[i+1].x*10 +array[i+1].y )
            {
                Point temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                change = true;
            }
        }
    }
}
char* strdublicate(char* array)
{
    char *cpy = new char[sizeof(array)/sizeof(*array)];
    cpy = array;
    return cpy;
}
int main()
{
    // Point array[3];
    // array[0] = {2,5};
    // array[1] = {2,1};
    // array[2] = {1,1};

    // // for (int i = 0; i <= 2; i++
    // // {
    // //     array[i] = {2,i};
    // // }
    
    // Sort(array, 3);

    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << array[i].x << array[i].y << std::endl;
    // }
  char word[] = "i want to die";
  char *word_2 = strdublicate(word);
  word_2 = "i want to die now";
  std::cout << word_2 << std::endl;
  std::cout << word << std::endl;
  

    // poly fmi = {{3,5,2},2};
    // poly nbu = {{2,4},1};

    // poly unss = result(fmi,nbu);
    // //fmi.diff();
    // // poly nbu = diff_two(fmi);
    // // // //std::cout << fmi.coefs[0] << fmi.coefs[1] <<fmi.coefs[2] << std::endl;
   
    // for (int i = 0; i <= unss.power; i++)
    // {
    //     std::cout << unss.coefs[i] << std::endl;

    // }
    // std::cout << unss.power << std::endl;

    // Product one = {"screw driver",456,5.2};
    // Product two = {"hammer",324,8.2};
    // one.Print();
    // two.Print();
    // Product array[5];
    // for (int i = 0; i <= sizeof(array)/sizeof(array[0]); i++)
    // {
    //     array[i] = {};
    //     array->Print();
    // }  

}

//3x+5
           // => *== 12x^2 + 29x+ 15
//4x+3