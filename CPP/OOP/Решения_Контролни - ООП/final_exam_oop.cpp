#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
class Entry
{
    public:
    virtual ~Entry() = default;
    virtual unsigned int size() = 0;
    virtual bool contains(const std::string& s) = 0;
    virtual std::string name() = 0;
    virtual void des(std::istream& in) = 0;
    virtual void print_contains(const std::string &s) = 0;
    virtual void ser(std::ostream& out) = 0;
};

class Note : public Entry
{
    private:
    std::string note;
    std::string name_;
    public:
    Note() 
    {
        note = nullptr;
        name_ = nullptr;
    }
    Note(std::string note_, std::string name1_) : note(note_), name_(name1_)
    {} 
    unsigned int size()
    {
        return note.length();
    }
    bool contains(const std::string& s)
    {   
        bool flag = false;
        (note.find(s) != -1) ? flag = true : flag;
        return flag;
    }
    std::string name()
    {
        return this->name_;
    }
    void ser(std::ostream& out) 
    {
        out << name_ << ", " << note;
    }
    void print_contains(const std::string &s) 
    {
        contains(s) ? (std::cout << size() << "," << name() << std::endl) : (std::cout << "it's not in the string");
    }
    void des(std::istream& in) 
    {
        in >> name_ >> note;
        name_[name_.length() - 1] = '\0';
    }

};

class Dictionary : public Entry
{
    private:
    std::vector<Entry*> elements;
    public:
    unsigned int size()
    {
        unsigned int length = 0;
        for (size_t i = 0; i < elements.size(); i++)
        {
            length += elements[i]->size();
        }
        return length;
    }
    bool contains(const std::string& s)
    {
        for (size_t i = 0; i < elements.size(); i++)
        {
             if (elements[i]->contains(s))
             {
                 return true;
             }
        }
        return false;
    }

    void addEntry(Entry *entry)
    {
        elements.push_back(entry);
    }
//     void ser(std::ostream& out) 
//     {
//         out << name_ << ", " << note;
//     }
//     void print_contains(const std::string &s)
//     {
//         contains(s) ? (std::cout << size() << "," << name() << std::endl) : (std::cout << "it's not in the string");
//     }
//     void des(std::istream& in) 
//     {
//         in >> name_ >> note;
//         name_[name_.length() - 1] = '\0';
//     }
};


int main()
{
    Note n1("Hello", "Note");
    std::cout << n1.name() << std::endl;
    std::cout << n1.size() << std::endl;
    n1.ser(std::cout) ;
    std::cout << std::endl;
    n1.print_contains("o");
    n1.des(std::cin);
    n1.ser(std::cout);
}