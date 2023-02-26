#include <iostream>
#include <string>
#include <cstring>
#include <vector>

class Entry
{
    public:
    virtual unsigned int size() = 0;
    virtual bool contains(const char* s) = 0;
    virtual std::string name() = 0;
};

class Note : public Entry
{
    private:
    char* note;
    public:
    Note(char* note_) : note(note_){}
    unsigned int size()
    {
        return strlen(note);
    }
    bool contains(const char* s)
    {
       for (size_t i = 0; i < this->size(); i++)
       {
           if (strcmp(note,s) == 1)
           {
               return true;
           }
           else
           {
               return false;
           }
           
       }
       
    }
    std::string name()
    {
        std::string name = "Note";
        return name;
    }
};

class Directory : public Entry
{
    private:
    std::vector<Note*> elements;
    public:
    
    unsigned int size()
    {
        unsigned int sum = 0;
        for (size_t i = 0; i < elements.size(); i++)
        {
            sum += elements[i]->size();
        }
        return sum;
        
    }
    
    bool contains(const char* s)
    {
        bool flag = false;
        for (size_t i = 0; i < elements.size(); i++)
        {
            if (this->elements[i]->contains(s) == true)
            {
                std::cout << "vleznah";
                flag = true;
            }
            else
            {
                flag;
            }
            
        }
        return flag;
    }
    std::string name()
    {
        std::string name = "Directory";
        return name;
    }
    void addEntry(Note* entry)
    {
        this->elements.push_back(entry);
    }
    std::vector<Directory*> addEntry(Directory* entry)
    {
        unsigned int sum = 0;
        for (size_t i = 0; i < elements.size(); i++)
        {
            sum += elements[i]->size();
        }
        int newSize = sum + entry->size();
        std::vector<Directory*> newvec;
        newvec.push_back(this);
        newvec.push_back(entry);
        return newvec;
    }
    
};

int main()
{
    Note n1("Hello");//5
   std::cout << n1.name()<<std::endl;
   std::cout << n1.size() <<std::endl;
   std::cout << std::boolalpha << n1.contains("zzzz")<<std::endl;
   std::cout << std::boolalpha << n1.contains("Hell")<<std::endl;
    Note n2("Darkness");//8
    Note n3("My old friend");//13


   Directory d1;
   d1.addEntry(&n1);
   d1.addEntry(&n2);
   d1.addEntry(&n3);

    std::cout << d1.name()<< std::endl; 
    std::cout << std::boolalpha << d1.contains("zero") <<std::endl;  
    std::cout << d1.size()<< std::endl;

   Directory d2;
   d2.addEntry(&n1);
   d2.addEntry(&n2);

   d1.addEntry(&d2);
   std::cout << d1.size() << std::endl;
}