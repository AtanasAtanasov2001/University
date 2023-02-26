#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
class Temperature
{
    private:
    int min_temp;
    int mid_temp;
    int max_temp;

    public:
    Temperature()
    {
        min_temp = mid_temp = max_temp = 12;
    }
    Temperature(int min, int avg, int max) 
    {
        if(min <= avg && avg <= max)
        {   
            min_temp = min;
            mid_temp = avg;
            max_temp = max;
            std::cout << "The temps are alligned" << std::endl;
        }
        else
        { 
            min_temp = mid_temp = max_temp = 12;
            std::cout << "The temps are not alligned" << std::endl;
        }
    }
    ~Temperature()
    {
        min_temp = mid_temp = max_temp = 0;
    }
    int GetMin() const
    {
        return this->min_temp;
    }
    int GetAverage() const
    {
        return this->mid_temp;
    }
    int GetMax() const
    {
        return this->max_temp;
    }

    void SetMin(int min) 
    {
        this->min_temp = min;
    }
    void SetAverage(int avg) 
    {
        this->mid_temp = avg;
    }
    void SetMax(int max)
    {
       this->max_temp = max;
    }
    int GetAmplitude() const
    {
        return this->max_temp - this->min_temp;
    }

    bool operator==(const Temperature& other ) const
    {
        return (this->GetMax() == other.GetMax()) && (this->GetMin() == other.GetMin()) && (this->GetAverage() == other.GetAverage());
    }
    bool operator!=(const Temperature& other) const
    {
        return (*this == other ? false: true);
    }
    bool operator<(const Temperature& other) const
    {
        return (this->GetMax() < other.GetMax()) && (this->GetMin() < other.GetMin()) && (this->GetAverage() < other.GetAverage());
    }
    bool operator>(const Temperature& other) const
    {
        return (!(*this <= other));
    }
    bool operator<=(const Temperature& other) const
    {
        return (*this < other) || (*this == other);
    }
    bool operator>=(const Temperature& other) const
    {
        return (!(*this <= other)) || (*this == other);
    }
};

class Forecast
{
    private:
    std::string name;
    Temperature t;

    public:
    Forecast() = default;
    Forecast(const std::string Place, Temperature const& Temp) : name(Place), t(Temp){}
    Forecast& operator=(const Forecast& other)
    {
        if(this != &other)
        {
            this->name = other.name;
            this->t = other.t;
        }
        return *this;
    }
    Forecast(const Forecast& other)
    {
        this->name = other.name;
        this->t = other.t;
    }
    std::string GetPlace() const
    {
        return this->name;
    }
    Temperature GetTemperature() const
    {
        return this->t;
    }
    void UpdateIfHotter(Forecast const& F)
    {
        if ((this->name == F.name) && (this->t < F.t))
        {
            this->t = F.t;
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Forecast& F)
    {
        out << F.name <<  " The min temp is: " << F.t.GetMin() 
                      <<  " The mid temp is: " << F.t.GetAverage()
                      <<  " The max temp is: " << F.t.GetMax()<< std::endl;
    }
    friend std::istream& operator>>(std::istream& in, Forecast& F)
    {
        int min,avg,max;
        in >> F.name >> min >> avg >> max;
        F.t.SetMin(min);
        F.t.SetAverage(avg);
        F.t.SetMax(max);
    }
};

//=================TASK2===========================

class Employees
{
    private:
    std::string name;
    int work_exp;
    double salary;
    

    public:
    Employees() = default;
    Employees(std::string name_, int work_exp_,double salary_) :
    name(name_),work_exp(work_exp_),salary(salary_){}
    std::string GetName()
    {
        return this->name;
    }
    int GetWork_exp()
    {
        return this->work_exp;
    }
    double GetSalary()
    {
        return this->salary;
    }
    virtual void print()
    {
        std::cout << "Name: " << name << " work_exp: " << work_exp << " salary: " << salary << std::endl;
    }
};
class Programmer : public Employees
{
    private:
    std::string program_language;
    std::string project;
    public:
    Programmer() = default;
    Programmer(std::string name_, int work_exp_,double salary_, std::string project_, std::string program_language_) : 
    Employees(name_,  work_exp_, salary_)
    {
        project = project_;
        program_language = program_language_;
    }
    void print() override
    {
        Employees::print();
        std::cout << "Prog_language: " << program_language << "Project: " << project << std::endl; 
    }
};
class QA : public Employees
{
    private:
    bool occupation;
    std::string project;
    public:
    QA() = default;
    QA (std::string name_, int work_exp_,double salary_, std::string project_, bool occupation_) : 
    Employees(name_,  work_exp_, salary_)
    {
        project = project_;
        occupation = occupation_;
    }
    void print() override
    {
        Employees::print();
        std::cout << "Occupation: " << occupation << "Project: " << project << std::endl; 
    }
};

class Manager : public Employees
{
    private:
    int subordinates;
    public:
    Manager() = default;
    Manager(std::string name_, int work_exp_,double salary_,int subs_) :
    Employees(name_,work_exp_,salary_)
    {
        subordinates = subs_;
    }
    void print() override
    {
        Employees::print();
        std::cout << "subordinates " << subordinates << std::endl; 
    }
};

class Company
{
    private:
    std::vector<Employees*> servants;
    public:

    Company() = default;
    Company(std::vector<Employees*> s1) : servants(s1){}
    void hire_emplyee(Employees &new_man)
    {
        servants.push_back(&new_man);
    }
    void fire_employee(std::string name_employee)
    {
        for (size_t i = 0; i < servants.size(); i++)
        {
            if(servants[i]->GetName() == name_employee)
            {
                servants.erase(servants.begin() + i);
                i--;
            }
        }
    }
    void fire_employee(int work_exp)
    {
        for (size_t i = 0; i < servants.size(); i++)
        {
            if(servants[i]->GetWork_exp() < work_exp)
            {
                servants.erase(servants.begin() + i);
                i--;
            }
        }
    }
    void print()
    {
        for (size_t i = 0; i < servants.size(); i++)
        {
            servants[i]->print();
            std::cout << std::endl;
        }
        
    }
    double allSalaries()
    {
        double sum = 0;
        for (size_t i = 0; i < servants.size(); i++)
        {
            sum += servants[i]->GetSalary();
        }
        return sum;
    }
    double avgSalary()
    {
        return (this->allSalaries() / servants.size());
    }

};
int main()
{
    // Temperature t_sofia(20,25,31);
    // Temperature t_pl(31,23,10);
    // Forecast f1("Sofia", t_pl);
    // std::cout << f1;
    // // std::cin >> f1;
    // // std::cout << f1;

    Programmer marto("Martin", 24, 4000.2, "assistant", "c++");
    Programmer nasko("Atanas", 5, 500.2, "student", "c++");
    QA ivailo("Ivailo",10, 1000.1,"evaluation", 0);
    Manager kalin("Kalin",120,6000.5,20);

    Company astea;
    astea.hire_emplyee(kalin);
    // astea.print();
    astea.hire_emplyee(marto);
    astea.hire_emplyee(ivailo);
    astea.hire_emplyee(nasko);
    // astea.print();
    std::cout << astea.allSalaries() << std::endl;
    std::cout << astea.avgSalary()<< std::endl;
    astea.fire_employee("Ivailo");
    
    // astea.print();
    astea.fire_employee(30);
    astea.print();
}