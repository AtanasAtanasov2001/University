#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
class Station
{
    protected:
    char name[20];
    size_t ser_num;
    size_t capacity;
    size_t num_of_trains;
    bool can_go;

    public:
    Station() = default;
    Station(char* name_, std::function<size_t(size_t,char*)> f1)
    {   
        strcpy(name,name_);
        capacity = f1(ser_num,name);
    }
    Station& operator=(Station& other)
    {
        if(this != &other)
        {
            strcpy(this->name, other.name);
            this->ser_num = other.ser_num;
            this->capacity = other.capacity;
            this->num_of_trains = other.num_of_trains;
            this->can_go = other.can_go;
        }
        return *this;
    }
    ~Station()
    {
        ser_num = capacity = num_of_trains = 0;
        can_go = 0;
    }
    size_t GetNT()
    {
        return num_of_trains;
    }
    void SetNT(size_t newNum)
    {
        this->num_of_trains = newNum;
    }
    bool GetCanGo()
    {
        return can_go;
    }
    void SetCanGo(bool newVal)
    {
        can_go = newVal;
    }

};
class CommonStation : public Station
{
    private:
    Station next_station;

    public:
    CommonStation() = default;
    CommonStation(char* name_, std::function<size_t(size_t,char*)> f1) : Station(name_,f1)
    {}
    void forbidGoing()
    {
        bool denial = 0;
        this->SetCanGo(denial);
    }
    void allowGoing()
    {
        bool permission = 1;
        this->SetCanGo(permission);
    }
    void shutStation()
    {
        this->forbidGoing();
        next_station.~Station();
    }
};  
class EndStation : public Station
{
    private:
    bool can_be_removed;
    public:
    EndStation() = default;
    EndStation(char* name_, std::function<size_t(size_t,char*)> f1) : Station(name_,f1)
    {}

    bool GetCR()
    {
        return can_be_removed;
    }
    void SetCR(bool newVal)
    {
        this->can_be_removed = newVal;
    }
    void forbidRemoving()
    {
        bool removed = 0;
        SetCR(removed);
    }
    void allowRemoving()
    {
        bool removed = 1;
        SetCR(removed);
    }
}; 

class SetterStation : public Station
{
    private:
    Station left_station;
    Station right_station;
    bool LS_can_go;
    bool RS_can_go;
    public:
    SetterStation() = default;
    SetterStation(char* name_, std::function<size_t(size_t,char*)> f1) : Station(name_,f1)
    {}
    void allowRS()
    {   
        RS_can_go = 1;
        right_station.SetCanGo(RS_can_go);
    }
    void denyRS()
    {   
        RS_can_go = 0;
        right_station.SetCanGo(RS_can_go);
    }
    void allowLS()
    {   
        RS_can_go = 1;
        right_station.SetCanGo(LS_can_go);
    }
    void denyLS()
    {   
        LS_can_go = 0;
        right_station.SetCanGo(LS_can_go);
    }
    void shutStation()
    {
        this->SetCanGo(0);
        this->denyRS();
        this->denyLS();
        this->left_station.~Station();
        this->right_station.~Station();
    }
};

class Train
{
    private:
    size_t train_num;
    size_t indicator;
    Station current;
    std::string type;

    public:
    Train() = default;
    Train(size_t train_num_,Station current_)
    {
        train_num = train_num_;
        current = current_;
    }
    ~Train()
    {
        this->train_num = this ->indicator = 0;
        current.~Station();
        type = nullptr;
    }
    bool go_next()
    {
        return current.GetCanGo();
    }
    void remove_train()
    {
        if(current.GetCanGo() == 0)
        {
            this->~Train();
        }
    }
};
int main()
{
    return 0;
}
