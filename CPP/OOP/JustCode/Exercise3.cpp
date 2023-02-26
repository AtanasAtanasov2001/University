#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

class WritingInstrument
{
    private:
    std::string type;
    size_t year_production;
    public:
    WritingInstrument() = default;
    WritingInstrument(std::string type_,size_t year_production_)
    {
        type = type_;
        year_production = year_production_;
    }
    ~WritingInstrument()
    {
        year_production = 0;
    }
    WritingInstrument(WritingInstrument& other)
    {
        this->type = other.type;
        this->year_production = other.year_production;
    }
    WritingInstrument& operator=(const WritingInstrument& other) 
    {
        if(this != &other)
        {
            this->type = other.type;
            this->year_production = other.year_production;
        }
        return *this;
    }
    std::string GetType()
    {
        return this->type;
    }
    void SetType(std::string& other_type)
    {
        this->type = other_type;
    }
    size_t GetYP()
    {
        return this->year_production;
    }
    void SetYP(size_t &other_YP)
    {
        this->year_production = other_YP;
    }
    friend std::ostream& operator<<(std::ostream &out,const WritingInstrument& other)
    {
        out << other.type << other.year_production << std::endl;
    }
    friend std::istream& operator>>(std::istream &in, WritingInstrument other)
    {
        in >> other.type >> other.year_production ;
    }
};

class Marker : public WritingInstrument
{
    private:
    std::string color;
    public:
    Marker() = default;
    Marker(std::string type_,size_t year_production,std::string color_) : WritingInstrument(type_,year_production)
    {
        color = color_;
    } 
    Marker(Marker& other)
    {
        WritingInstrument::operator=(other);
        this->color = other.color;
    }
    Marker& operator=(const Marker& other)
    {
        if(this != &other)
        {
            *this = other;
             this->color = other.color;
        }
        return *this;
    }
    std::string GetColor()
    {
        return this->color;
    }
    void SetColor(std::string& other)
    {
        this->color = other;
    }
};
class Pencil : public WritingInstrument
{
    private:
    size_t hardness;
    public:
    Pencil() = default;
    Pencil(std::string type_,size_t year_production,size_t hardness_) : WritingInstrument(type_,year_production)
    {
        hardness = hardness_;
    }
    Pencil(Pencil& other)
    {
        WritingInstrument::operator=(other);
    }
    Pencil& operator=(const Pencil& other)
    {
        if(this != &other)
        {
            *this = other;
            this->hardness = other.hardness;
        }
        return *this;

    }
    size_t GetHardness()
    {
        return this->hardness;
    }
    void SetHardness(size_t &other_HD)
    {
        this->hardness = other_HD;
    }

};



class Device
{
    protected:
    std::string maufacturer;
    public:
    virtual void print() = 0;
    virtual int get_perf() = 0;
};

class Laptop : public Device
{
    private:
    size_t speed;
    public:
    Laptop() = default;
    Laptop(std::string manufact_, size_t speed_)
    {
        this->maufacturer = manufact_;
        speed = speed_;
    }
    void print()
    {
        std::cout << this->maufacturer << this->speed << std::endl;
    }
    int get_perf()
    {
        return this->speed;
    }
};

class Car : public Device
{
    private:
    int power;
    int area_engine;
    public:
    Car() = default;
    Car(std::string manufact, int power_, int area_engine_)
    {
        this->maufacturer = manufact;
        power = power_;
        area_engine = area_engine_;
    }
    void print()
    {
        std::cout << this->maufacturer << this->power << this->area_engine << std::endl;
    }
    int get_perf()
    {
        return this->power;
    }
};
class Inventory
{
    private:
    std::vector<Device*> stock;
    public:
    void print()
    {
        for (size_t i = 0; i < stock.size(); i++)
        {
            stock[i]->print();
            std::cout << std::endl;
        }
        
    }
    void add(Device& other)
    {
        this->stock.push_back(&other);
    }
    bool alligned()
    {
        for (size_t i = 0; i < stock.size() - 1; i++)
        {
            if(stock[i]->get_perf() > stock[i + 1]->get_perf())
                return false;
        }
        return true;
        
    }
};

int main()
{
    // WritingInstrument w1("gadulka", 1999);
    // WritingInstrument w2("kaval", 2014);
    // Marker m1("permanenten", 2020,"Black");
    // Pencil p1("Grafiten",2021,8);
    // std::cout << m1;

    Laptop asus("Asus", 2500);
    Laptop acer("Acer", 3000);
    Car vw("VW",1500,2500);
    Inventory i1;
    i1.add(asus);
    i1.add(acer);
    i1.add(vw);
    i1.print();
    std::cout << std::boolalpha << i1.alligned();

}