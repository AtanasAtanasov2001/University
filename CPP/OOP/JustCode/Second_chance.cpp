#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

// Разглеждаме система за резервиране на билети за концерт. 
// За всеки билет трябва да се съхраняват дата и час на представлението, номер на залата (цяло число в интервала 1 – 10) и 
//базова цена (число с плаваща запетая). Системата поддържа три типа билети:

// Обикновен билет: който съдържа номер на ред и номер на място (също цели числа в интервала 1-100 всяко)

// Поименен билет: който съдържа името на ползвателя (символен низ с произволна дължина) и номер на ложата, 
// за която е абониран ползвателя (цяло число между 1 и 100)

// Билет за специален гост: подобен на поименния, но позволява също среща с актьорите преди представлението и 
// съответно пази информация за датата и часа на тази среща с актьорите

// Цената за всеки вид билет се определя по различен начин. За обикновения билет цената е базовата цена, съхранена в билета. 
// За поименния – три пъти по-висока от базовата цена, докато билетът за специален гост винаги е безплатен.

// Вашата задача е:

// 1. Реализирайте 4 класа – един абстрактен за базовия билет и три за съответните конкретни типове.  
// Реализирайте класовете според правилата на ООП, като използвате полиморфизъм при определянето на цената на билетите

// 2. Реализирайте функция, която получава като аргумент масив от билети, съдържащ произволна комбинация от трите вида билети 
// и връща като резултат общата сума за цените на всички билети

// 3. Демонстрирайте функцията за сумиране на цените на билетите с нейно извикване над примерни данни, 
// съдържащи поне по един от всеки вид билети
class Ticket
{
    protected:
    size_t date;
    size_t hour;
    size_t room_num;
    double base_price;

    public:
    virtual double GetPrice() = 0;
};

class CommonTicket : public Ticket
{
    private:
    size_t row_num;
    size_t seat_num;

    public:
    CommonTicket() = default;
    CommonTicket(size_t date_,size_t hour_,size_t room_num_,double base_price_,size_t row_num_, size_t seat_num_ )
    {
        this->date = date_;
        this->hour = hour_;
        this->room_num = room_num_;
        this->base_price = base_price_;
        this->row_num = row_num_;
        this->seat_num = seat_num_;
    }
    CommonTicket(CommonTicket& other)
    {
        this->date = other.date;
        this->hour = other.hour;
        this->room_num = other.room_num;
        this->base_price = other.base_price;
        this->row_num = other.row_num;
        this->seat_num = other.seat_num;
    }
    ~CommonTicket()
    {
        this->date = this->hour = this->room_num = this->base_price = this->row_num = this->seat_num = 0;
    }
    double GetPrice()
    {
        return this->base_price;
    }
};

class NamedTicket : public Ticket
{
    private:
    std::string name;
    size_t residence;
    public:
    NamedTicket() = default;
    NamedTicket(size_t date_,size_t hour_,size_t room_num_,double base_price_, std::string name_, size_t residence_)
    {
        this->date = date_;
        this->hour = hour_;
        this->room_num = room_num_;
        this->base_price = base_price_;
        this->name = name_;
        this->residence = residence_;
    }
    NamedTicket(NamedTicket &other)
    {
        this->date = other.date;
        this->hour = other.hour;
        this->room_num = other.room_num;
        this->base_price = other.base_price;
        this->name = other.name;
        this->residence = other.residence;
    }
    ~NamedTicket()
    {
        this->name = nullptr;
        this->date = this->hour = this->room_num = this->base_price = this->residence= 0;
    }
    double GetPrice()
    {
        return base_price * 3;
    }
};

class SpecialGuestTicket : public Ticket
{
    private:
    std::string name;
    size_t residence;
    size_t date_meeting;
    size_t hour_meeting;
    public:
    SpecialGuestTicket() = default;
    SpecialGuestTicket(size_t date_,size_t hour_,size_t room_num_,double base_price_, std::string name_, 
    size_t residence_, size_t date_meeting_, size_t hour_meeting_)
    {
        this->date = date_;
        this->hour = hour_;
        this->room_num = room_num_;
        this->base_price = base_price_;
        this->name = name_;
        this->residence = residence_;
        this->date_meeting = date_meeting_;
        this->hour_meeting = hour_meeting_;
    }
    SpecialGuestTicket(SpecialGuestTicket& other)
    {
        this->date = other.date;
        this->hour = other.hour;
        this->room_num = other.room_num;
        this->base_price = other.base_price;
        this->name = other.name;
        this->residence = other.residence;
        this->date_meeting = other.date_meeting;
        this->hour_meeting = other.hour_meeting;
    }
    ~SpecialGuestTicket()
    {
        this->name = nullptr;
        this->date = this->hour = this->room_num = this->base_price = this->residence =  this->date_meeting =  this->hour_meeting = 0;
    }
    std::string GetSPGName()
    {
        return this->name;
    }
    double GetPrice()
    {
        return 0;
    }

};

double allTicketsPrice(std::vector<Ticket*> &a)
{
    double sum = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        sum += a[i]->GetPrice();
    }
    return sum;
}
int main()
{
    CommonTicket t1(10,18,6,15.5,4,20);
    std::cout << "The price of the common ticket t1 is: " << t1.GetPrice() << std::endl;
    NamedTicket n1(10,18,6,15.5,"Bojidar",3);
    std::cout << "The price of the named ticket n1 is: " << n1.GetPrice() << std::endl;
    SpecialGuestTicket s1(10,18,6,15.5,"Vasil Naidenov", 4, 10,21);
    std::cout << "The price of the special guest ticket s1 is: " << s1.GetPrice() << " ,and his name is: "<< s1.GetSPGName() << std::endl;


    std::vector<Ticket*> tickets;
    tickets.push_back(&t1);
    tickets.push_back(&n1);
    tickets.push_back(&s1);
    std::cout << "The price of all tickets is: " << allTicketsPrice(tickets) << std::endl;
    return 0;


}