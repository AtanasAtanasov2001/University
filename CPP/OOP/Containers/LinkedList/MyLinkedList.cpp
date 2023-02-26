#include <iostream>

template<typename T>
struct Box
{
    T data;
    Box* next;

    Box() = default;
    Box(T data_, Box* next_ = nullptr) : data(data_){} 
};

template<typename T>
class MyLinkedList
{
    private:
        Box<T>* first;
    public:
        MyLinkedList()
        {
            this->first = nullptr;
        }
        void pushFront(const T& other)
        {
            Box<T>* newbox = new Box<T>(other, nullptr);
            newbox->next = first;
            first = newbox;
        }
        void pushBack(const T& other)
        {
            Box<T>* newbox = new Box<T>(other, nullptr);
            Box<T>* current = first;

            if(first == nullptr)
            {
                first = newbox;
                return;
            }
            while (current->next)
            {
                current = current->next;
            }
            current->next = newbox;
            newbox->next = nullptr;
            
        }
        void reverse()
        {
            Box<T>* prevoius = nullptr;
            Box<T>* next = nullptr;
            Box<T>* current = first;

            while (current)
            {
                next = current->next;
                current->next = prevoius;
                prevoius = current;
                current = next;
            }
            first = prevoius;
            
        }
        void remove()
        {
            Box<T>* current = first;
            Box<T>* currentNext = nullptr;
            while(current)
            {
                currentNext = current->next;
                free(current);
                current = currentNext;
            }
            first = nullptr;
        }
        bool popFront()
        {
            Box<T>* current = first;
            if(current = nullptr)
            {
                return false;
            }

            first = first->next;
            delete current;
            current = nullptr;
            std::cout << std::endl;
            return true;
        }
        bool popBack()
        {
            Box<T>* current = first;
            if(current == nullptr)
            {
                return false;
            }
            while(current->next->next)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            std::cout << std::endl;
            return true;

        }
        const T& getAt(T& newdata) const
        {
            Box<T>* current = first;
            while (current)
            {
                if(current->data == newdata)
                {
                    return current->data;
                }
                current = current->next;
            }
            std::cout << "Invalid!" << std::endl;
            return first->data;
        }
        size_t size() const
        {
            Box<T>* current = first;
            size_t size = 0;
            while (current != nullptr)
            {
                size++;
                current = current->next;
            }
            return size;

        }
        bool insertAt(size_t position, T& data_)
        {
            Box<T>* current = first;
            Box<T>* newbox = new Box<T>(data_);
            size_t index = 1;
            while (current)
            {
                if(position == 1)
                {
                    this->pushFront(data_);
                    return true;
                }
                else if ((position - 1) == index)
                {
                    newbox->next = current->next;
                    current->next = newbox;
                    return true;
                }
                current = current->next;
                index++;
            }
            std::cout << "Out of range index was choosen!" << std::endl;
	        return false;
        }
        bool deleteAt(size_t position)
        {
            Box<T>* current = first;
            size_t index = 1;

            while(current)
            {
                if(position == 1)
                {
                    this->popFront();
                    return true;
                }
                else if((position - 1 ) == index)
                {
                    Box<T>* temp = current->next->next;
                    free(current->next);
                    current->next = temp;
                    return true;
                }
                current = current->next;
                index++;
            }
            	std::cout << "Out of range index was choosen!" << std::endl;
	            return false;
        }
        void swap(size_t position1, size_t position2)
        {
            Box<T>* prevFirst = nullptr;
            Box<T>* currFirst = first;
            Box<T>* prevSecond = nullptr;
            Box<T>* currSecond = first;
            size_t index = 0;

            while(currFirst)
            {
                if(index == (position1 - 1))
                {
                    break;
                }
                index++;
                prevFirst = currFirst;
                currFirst = currFirst->next;
            }
            while(currSecond)
            {
                if(index == position2)
                {
                    break;
                }
                index++;
                prevSecond = currSecond;
                currSecond = currSecond->next;
            }

            if(prevFirst != nullptr)
            {
                prevFirst->next = currSecond;
            }
            else
            {
                first = currSecond;
            }
            if(prevSecond != nullptr)
            {
                prevSecond->next = currFirst;
            }
            else
            {
                first = currFirst;
            }
            Box<T>* temp = currSecond->next;
            currSecond->next = currFirst->next;
            currFirst->next = temp;
        }
        void print()
        {
            Box<T>* newbox = first;
            while(newbox)
            {
                std::cout << newbox->data <<", ";
                newbox = newbox->next;
            }
            std::cout << std::endl;
        }
};

int main()
{
    MyLinkedList<int> l1;
    l1.pushFront(1);
    l1.pushBack(2);
    l1.pushFront(0);
    l1.print();
    //l1.reverse();
    //l1.print();
    //l1.remove();
    //std::cout << l1.popFront();
    //std::cout << l1.popBack();
     int newdata = 4;
    // std::cout << l1.getAt(newdata);
    //std::cout << l1.size();
    std::cout << l1.insertAt(2,newdata) << std::endl;
    l1.print();
    l1.swap(1,2);
    l1.print();
    
}
