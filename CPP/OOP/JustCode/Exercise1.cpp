#include <iostream>
#include <fstream>
#include <vector>
#include <string>


template <typename T>
class PriceTag
{
    private:
    double price;
    public:

    PriceTag(){}
    PriceTag(double price_) : price(price_){}
    double getPrice()
    {
        return this->price;
    }
    friend std::ostream& operator<<(std::ostream &out, const PriceTag<T>& p);
    friend std::istream& operator<<(std::istream in, PriceTag<T>& p);
    void discount(int percent)
    {
        price -=( percent/100) * price;
    }
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const PriceTag<T>& p)
{
    out << p.price << std::endl;
}
template <typename T>
std::ostream& operator>>(std::istream& in,  PriceTag<T>& p)
{
    in >> p.price;
}

template<typename T>
class PriceCatalog
{
    private:
    std::vector<PriceTag<T>*> catalog;

    public:
    PriceCatalog ()
    {
        catalog = nullptr;
    }
    PriceCatalog (std::vector<PriceTag<T>*> catalog_)
    {
        catalog = catalog_;
    }
    PriceCatalog(const PriceCatalog<T> &other)
    {
        this->catalog = other.catalog;
    }
    ~PriceCatalog()
    {
        delete[] this->catalog;
    }
    PriceCatalog& operator=(const PriceCatalog<T> &other)
    {
        if(this != &other)
        {
            this->catalog = other.catalog;
        }
        return this;
    }
    PriceCatalog& operator+=(const PriceCatalog<T> &other)
    {
        if(this != &other)
        {
            this->catalog += other.catalog;
        }
        return this;
    }
    friend std::ostream& operator<<(std::ostream& out, const PriceCatalog<T> &p);
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const PriceCatalog<T> &p)
{
    out << p.catalog << std::endl;
}

class Timestamp
{
    protected:
    unsigned long data;

    public:

    Timestamp()
    {
        data = 0;
    }
    Timestamp(unsigned long data_)
    {
        data = data_;
    }
    unsigned long getValue()
    {
        return this->data;
    }
    void setValue(unsigned long other)
    {
        data = other;
    }
    friend std::ostream& operator<<(std::ostream &out, const Timestamp& p);
    friend std::istream& operator>>(std::istream &in, Timestamp& p);

    Timestamp& operator+=(unsigned long additional)
    {
        this->data += additional;
        return *this;
    }
    Timestamp& operator+(unsigned long additional_)
    {
        Timestamp temp(*this);
        temp += additional_;
        return temp;
    }
};
std::ostream& operator<<(std::ostream &out, const Timestamp& p)
{
    out << p.data<< std::endl;
}
std::istream& operator>>(std::istream &in, Timestamp &p)
{
    unsigned long input;
    in >> input;
    p.setValue(input);
}

class TimestampWithDescription : public Timestamp
{
    private:
    std::string description;

    public:
    TimestampWithDescription()
    {
        description = nullptr;
    }
    TimestampWithDescription(std::string description_)
    {
        description = description_;
    }
    ~TimestampWithDescription()
    {
        description.clear();
    }
    TimestampWithDescription (const TimestampWithDescription& other)
    {
        this->description = other.description;
    }
    TimestampWithDescription &operator=(const TimestampWithDescription& other)
    {
        if(this != &other)
        {
            this->description = other.description;
        }
        return *this;
    }
    std::string getDescription()
    {
        return this->description;
    }
    void setDescription(std::string &other)
    {
        this->description = other;
    }
    friend std::ostream& operator<<(std::ostream &out, const TimestampWithDescription& p);
    friend std::istream& operator<<(std::istream &in, TimestampWithDescription& p);
};
 std::ostream& operator<<(std::ostream &out, const TimestampWithDescription& p)
 {
     out << p.description << p.data << std::endl;
 }
  std::istream& operator>>(std::istream &in,  TimestampWithDescription& p)
  {
      std::string new_description;
      in >> new_description;
      p.setDescription(new_description);
      unsigned long new_value;
      in >> new_value;
      p.setValue(new_value);
  }

int main()
{
    Timestamp t1(50);
     unsigned long additional = 500;
   
    // t1.setValue(additional);
    // std::cout <<  t1.getValue();

    // std::cout << (t1 + additional);
    // std::cout << t1;
    // std::cin >> t1;
    // std::cout << t1;
    TimestampWithDescription t_d1("drug");
    std::cout << t_d1.getDescription();
    std::cout << t_d1.getValue();
     t_d1.setValue(additional);
     std::cout << t_d1;
     std::cin >> t_d1;
     std::cout << t_d1;
    return 0; 
}
    