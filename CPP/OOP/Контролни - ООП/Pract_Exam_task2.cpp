#include <iostream>
#include <functional>
template<typename T>
class StandartMonoid
{
    private:
    T element;
    void closeMonoid()
    {
        delete this->element;
    }
    std::function<void(int)> zip()
    {

    }
    public:
    bool isIsomorphicTo(StandartMonoid<T> &other, std::function<void(T)>)
    {

    }
    StandartMonoid constructInfiniteMonoidNaturals()
    {
        
    }
    void multiplyMonoids();
};
template<typename T>
bool StandartMonoid<T>::isIsomorphicTo(StandartMonoid<T> &other, std::function<void(T)> func)
{
    if ()
    {
        /* code */
    }
    
}
int main()
{

}