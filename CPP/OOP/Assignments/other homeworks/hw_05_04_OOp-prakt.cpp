#include <iostream>
#include <cstring>
#include "vector.cpp"
#include "vector.h"
#include <typeinfo> //that's used in the if statement to check the type...inache kakto vesko checkvashe dali sa 
                    //pravougulnici ili krugove az checkvam dali e tip CD

class CD
{
    private:
    std::string manufacturer;
    double availableMemory;
    size_t totalMemory;
    bool rewritable;
    double price;
    std::string type;

    public:
    CD () {}

    CD(std::string manufacturer_, size_t totalMemory_, bool rewritable_, double price_) : manufacturer(manufacturer_),
    totalMemory(totalMemory_), rewritable(rewritable_), price(price_)
    {
        availableMemory = totalMemory;
        type = "CD-ROM";
    }
    
    friend std::ostream& operator<< (std::ostream &out, const CD& other)
    {
        out 
            <<"The manufactorer is: "<< other.manufacturer <<" , "
            <<"The available memory is: "<< other.availableMemory <<" , "
            <<"The total memory is:"<< other.totalMemory<<" ,"
            <<"Is the disk rewritable?"<<std::boolalpha << other.rewritable <<" , "
            <<"The price of the disk is: "<< other.price<<" , "
            <<"The type of the disk is: "<<other.type << " , "
            <<std::endl;
        return out;
    }

    friend std::istream& operator>> (std::istream &in, CD& other)
    {
        in >> other.manufacturer >> other.availableMemory >> other.totalMemory >> other.rewritable >> other.price >> other.type;
        return in;
    }
};

int main()
{
    Vector<CD> c;
    CD cd1 ("Toshiba", 16, 1, 10.5);
    CD cd2 ("Vodafon", 8, 0, 5.5);

    std::ofstream out ("CD.txt");

    out << cd1;
    out << cd2;

    out.close();

    std::ifstream in("CD.txt");
    std::string row = "";
    while (!in.eof())
    {
        std::getline(in, row);
        std::string Manufacturer = "";
        
        int index = 0;

        for (; index < row.size(); index++)
        {
            if (row[index] == ' ')
            {
                index++;
                break;
            }
            Manufacturer += row[index];
        }

       // if (typeid(cd1) == typeid(CD)) // basically the only check - type of thing....i
                                       // think it's also possible without the if
        //{
            int manufacturer1 = 0;
            double availableMemory1 = 0;
            size_t totalMemory1 = 0;
            int rewritable1 = 0;
            double price1 = 0;
            int type1 = 0;
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        manufacturer1 *= 10;
                        manufacturer1 += (currentSymbol - '0');
                    }
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        availableMemory1 *= 10;
                        availableMemory1 += (currentSymbol - '0');
                    }
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        totalMemory1 *= 10;
                        totalMemory1 += (currentSymbol - '0');
                    }
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        rewritable1 *= 10;
                        rewritable1 += (currentSymbol - '0');
                    }
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        price1 *= 10;
                        price1 += (currentSymbol - '0');
                    }
                for(; index < row.size(); index++)
                    {
                        char currentSymbol = row[index];
                        if(currentSymbol == ' ')
                        {
                            index++;
                            break;
                        }

                        type1 *= 10;
                        type1 += (currentSymbol - '0');
                    }
            
        //}
        //c.push_back(cd1(manufacturer1,availableMemory1,totalMemory1,rewritable1,price1,type1));
    }

    in.close();

    return 0;
}