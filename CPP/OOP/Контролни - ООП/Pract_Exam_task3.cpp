#include<iostream>


template<typename T>
struct Box
{
    T data;
    Box* next;
    Box(T element) : data(element), next(nullptr){}
};

template<typename T>
struct Linkedlist
{
    Box<T>* first;

    Linkedlist()
    {
        this->first = nullptr;
    }

    ~Linkedlist()
    {
        delete[] this->first;    
    }

    T operator[](int position)
    {   
        int counter = 0;
        Box<T> *help = first; 
        
        if (counter == position)
        {
            return help->data;
        }
        else 
        {
            Box<T> *next = help->next;
            while (next->next != nullptr)
            {
                help = next;
                counter++;
                if (counter == position)
                {
                    return help->data;
                }
            }
            
        }
        
       
        
    }
    void addElement(T element)
    {
        if(this->first == nullptr)
        {
            this->first = new Box<T>(element);
        }
        else
        {
            Box<T> *help = first;
            while (help->next != nullptr)
            {
                Box<T> *next = help->next;
                help = next;
            }
            help->next = new Box<T>(element);
            
        }
    }
    void print()
    {

        if(this->first == nullptr)
        {
            std::cout <<" "<<std::endl;
        }
        else
        {
            Box<T> *help = first;
            while (help->next != nullptr)
            {
                std::cout << help->data << " ";
                Box<T> *next = help->next;
                help = next;
            }
            std::cout << help->data ;            
        }
        
    }
    
    
    bool isPalindrome()
    {
        if (this)
        {
            /* code */
        }
        
    }

};
template<typename T>
void swap(Linkedlist<T> &other, int position1, int position2) 
    {
        T temp1 = other[position1];
        T temp2 = other[position2];
        int cnt = 0;
        Box<T> *help = other.first;
        while (help->next != nullptr )
        {
            if (cnt == position1)
            {
                std::cout << help->data << std::endl;
                help->data = temp2;
                
            }
            if (cnt == position2)
            {
                std::cout << help->data << std::endl;
                help->data = temp1;
            }
             cnt++;
            Box<T> *next = help->next;
            help = next;
        }
        
    }

int main()
{
    Linkedlist<int> l;
    l.addElement(1);
    l.addElement(2);
    l.addElement(3);
    l.print();

    std::cout <<std::endl;
    std::cout << l[1] <<std::endl;

    swap(l,0,2);
    l.print();
    
    return 0;
}