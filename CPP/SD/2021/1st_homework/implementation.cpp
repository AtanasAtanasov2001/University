#include <iostream>
#include "interface.hpp"
#include <vector>
#include <cassert>
#include <exception>

//Mine inplementation of linkedQueue
template <typename DataType>
class LinkedQueue 
{
public:
    LinkedQueue(): begin(nullptr), end(nullptr) {}
   
    LinkedQueue(const LinkedQueue<DataType>& other);

    LinkedQueue<DataType>& operator=(const LinkedQueue<DataType>& other);
    ~LinkedQueue();

    void enqueue(const DataType& data);
    DataType dequeue();
    const DataType& first();
    bool isEmpty() const ;
    int Size();
    bool isFull() const {return false;}

private:
    struct node
    {
        DataType data;
        node* next;
        node(const DataType& data, node* n = nullptr)
            : data(data), next(n) {}
    } *begin, *end;
    int size = 0;

private:
    void clear();
    void copy(const node* start);
};

template<typename T>
void LinkedQueue<T>::copy(const node* start)
{
    assert(begin == nullptr && isEmpty());
    
    while(start) {
        enqueue(start->data);
        start = start->next;
    }
}

template <typename T>
void LinkedQueue<T>::clear() {
  while (!isEmpty()) {
      node* temp = begin;
      begin = begin->next;
      delete temp;
  }
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}
template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other.begin);
    }
    return *this;
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other) {
    begin = nullptr;
    copy(other.begin);
}


template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
    node* helper = new node(data);
    if(isEmpty())
    {
        begin = helper;
    }
    else {
        end->next = helper;
    }
    end = helper;
    size++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if(!isEmpty()) {
        T temp_value = begin->data;
        node* toDelete = begin;
        begin = begin->next;
        delete[] toDelete;
        size--;
        return temp_value;
    }
    throw std::invalid_argument("The queue is empty -> DEQUEUE");

}

template<typename T>
const T& LinkedQueue<T>::first(){
    if(!isEmpty()) {
        return begin->data;
    }
    throw std::invalid_argument("the queue is empty -> FIRST");
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const{
  return begin == nullptr;
}

template<typename T>
int LinkedQueue<T>::Size() {
    return this->size;
    
}

//=================================================================================
//the MrazMar task

const int DELIVERY_TIME = 60;
const int DELIVERY_QUANTITY = 100; 

//the pair structure, used in the queues 
template<typename T, typename P>
struct Pair {
    T data1;
    P data2;

    Pair () {}
    Pair(T data1_, P data2_) : data1(data1_), data2(data2_) {}
    ~Pair() = default;
};
//Implementation of the abstract class ActionHandler, used to print the messages
class AH_Implementation : public ActionHandler 
 {
    public:
    inline void onWorkerSend(int minute, ResourceType resource) override {
        
        std::cout << "W" << " " << minute << " ";
        switch(resource) {
            case ResourceType::banana : 
                std::cout << "banana" << "\n";
                break;
            case ResourceType::schweppes :
                std::cout << "schweppes" << "\n";
        }
    }
    inline void onWorkerBack(int minute, ResourceType resource) override {
        std::cout << "D" << " " << minute << " ";
        switch(resource) {
            case ResourceType::banana : 
                std::cout << "banana" << "\n";
                break;
            case ResourceType::schweppes :
                std::cout << "schweppes" << "\n";
                break;
        }
    }
    inline void onClientDepart(int index, int minute, int banana, int schweppes) override{
        std::cout << index << " " << minute << " " << banana << " " << schweppes << "\n";
    }
};

//a simple function, that returns the product, which the client wants more (bananas or schweppes)
ResourceType clientDemand(const Client &customer) {
    return customer.banana >= customer.schweppes ? ResourceType::banana : ResourceType::schweppes;
}
//"Mystore" from the example, inheriting the abstract class "Store"
//I named it MrazMar, beacause that's the title of the homework
class MrazMar : public Store {
    private:
    int workers_free;
    LinkedQueue<Pair<int, ResourceType>> workers_sent;//the pair shows the minute, the worker goes to supply and the resource he goes for
    LinkedQueue<Pair<Client, int>> clients_waiting;//the pair shows the client that waits and hes index;
    LinkedQueue<Client> clients_queue;//the clients in the store
    ActionHandler *actionHandler;//the pointer directing to ActionHandler, that i use to print the messages
    int store_bananas;//the quantity of bananas
    int store_schweppeses;//the quantity of schweppes
    int time = 0;//the variable which indicates the time

    public:
    MrazMar(){}

    inline void init(int workerCount, int startBanana, int startSchweppes) override  {
        this->workers_free = workerCount;
        this->store_bananas = startBanana;
        this->store_schweppeses = startSchweppes;
    }
    inline void setActionHandler(ActionHandler *handler) override {
        actionHandler = handler; 
    }
    
    inline void addClients(const Client *clients, int count) override {
        for (size_t i = 0; i < count; i++)
        {
            clients_queue.enqueue(clients[i]);
        }  
    }
   
    inline void advanceTo(int minute) override {
        int index = 0; 
        while( time <= minute ) {

            //1st MAIN validation
            //if i have clients in the store i send them in the waiting queue 
            if(!clients_queue.isEmpty()) {
                //I used a loop beacause of the case that multiple clients arrive at the same minute
                while(!clients_queue.isEmpty() && clients_queue.first().arriveMinute == time){
                    clients_waiting.enqueue(Pair<Client, int>(clients_queue.first(),index));
                    clients_queue.dequeue();
                    index++;
                } 
            }
            //2nd MAIN validation
            //when both of my queues are empty but i still have sent workers
            if(clients_queue.isEmpty() && clients_waiting.isEmpty()) {
                time++;
                //when it's time for the worker to return
                if(!workers_sent.isEmpty() && workers_sent.first().data1 + DELIVERY_TIME == time) {
                    actionHandler->onWorkerBack(workers_sent.first().data1 + DELIVERY_TIME, workers_sent.first().data2);
                    workers_sent.dequeue();
                    workers_free++;
                }
                continue;
            }
            
            //3rd MAIN validation
            //when it's time for the worker to come back
            while(!workers_sent.isEmpty() && workers_sent.first().data1 + DELIVERY_TIME == time) {
                actionHandler->onWorkerBack(workers_sent.first().data1 + DELIVERY_TIME, workers_sent.first().data2);
                //A validation whether the worker was sent for bananas or schweppeses
                if(workers_sent.first().data2 == ResourceType::banana) {
                    this->store_bananas += DELIVERY_QUANTITY;
                }else if (workers_sent.first().data2 == ResourceType::schweppes) {
                    this->store_schweppeses += DELIVERY_QUANTITY;
                }
                //if i have enough resources after the delivery, i service the client immediately
                if(!clients_waiting.isEmpty() && clients_waiting.first().data1.banana <= this->getBanana() && clients_waiting.first().data1.schweppes <= this->getSchweppes()) {
                    this->store_bananas -= clients_waiting.first().data1.banana;
                    this->store_schweppeses -= clients_waiting.first().data1.schweppes;
                    actionHandler->onClientDepart(clients_waiting.first().data2, time, 
                    clients_waiting.first().data1.banana, clients_waiting.first().data1.schweppes);
                    clients_waiting.dequeue();  
                }
                workers_sent.dequeue();
                workers_free++;
            } 

            
            //4th MAIN validation
            //when i have clients waiting to be serviced
            if(!clients_waiting.isEmpty()) {
                int size = clients_waiting.Size();
                //the variable size helps me iterate trough the loop
                while(size > 0 ) {
                    //when i have the desired products in stock i service the client
                    if( clients_waiting.first().data1.arriveMinute == time && this->getBanana() >=  clients_waiting.first().data1.banana && this->getSchweppes() >=  clients_waiting.first().data1.schweppes) {
                        actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute, clients_waiting.first().data1.banana,  clients_waiting.first().data1.schweppes);
                        this->store_bananas -=  clients_waiting.first().data1.banana;
                        this->store_schweppeses -=  clients_waiting.first().data1.schweppes;
                        clients_waiting.dequeue();
                        size--;
                        continue;
                    }
                    //when the amount of products in stock is no sufficient 
                    else {
                        //when the customer arrives but i dont have enough of the both resources, free worker and i havent sent a worker beforehand
                        if( clients_waiting.first().data1.arriveMinute == time && (this->getBanana() <  clients_waiting.first().data1.banana && this->getSchweppes() < clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && workers_sent.isEmpty()) {
                                Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, clientDemand(clients_waiting.first().data1));
                                workers_sent.enqueue(worker);
                                workers_free--;
                                actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, clientDemand(clients_waiting.first().data1));
                        }
                        //when the customer arrives but i dont have enough of the both resources, free worker and i have sent a worker beforehand
                        else if( clients_waiting.first().data1.arriveMinute == time && (this->getBanana() <=  clients_waiting.first().data1.banana && this->getSchweppes() <=  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && !workers_sent.isEmpty()) {
                            //when i have sent a worker for bananas beforehand and the next clients wants more than 0 scweppeses
                            if(workers_sent.first().data2 == ResourceType::banana && clients_waiting.first().data1.schweppes > 0) {
                                Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                                workers_sent.enqueue(worker);
                                workers_free--;
                                actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                            
                            }
                            //when  i have sent a worker for schweppeses beforehand and the next clients wants more than 0 bananas
                            else if(workers_sent.first().data2 == ResourceType::schweppes && clients_waiting.first().data1.banana > 0) {
                                Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                                workers_sent.enqueue(worker);
                                workers_free--;
                                actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                            }
                        }
                        //when the customer arrives and i have schweppeses but no bananas, free worker to send and havent sent a worker beforehand
                        else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() < clients_waiting.first().data1.banana && this->getSchweppes() >=  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && workers_sent.isEmpty() ) {
                            Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                            workers_sent.enqueue(worker);
                            workers_free--;
                            actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                        }
                        //when the customer arrives and i have schweppeses but no bananas,free worker and i haven't sent a worker for bananas
                        else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() < clients_waiting.first().data1.banana && this->getSchweppes() >=  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && !workers_sent.isEmpty() && workers_sent.first().data2 != ResourceType::banana ){
                            Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                            workers_sent.enqueue(worker);
                            workers_free--;
                            actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::banana);
                        } 
                        //when the customer arrives and i have schweppeses but no bananas, free worker, i have sent a worker beforehand but for bananas
                        //=> i skip the iteration for this customer
                         else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() < clients_waiting.first().data1.banana && this->getSchweppes() >=  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && !workers_sent.isEmpty() && workers_sent.first().data2 == ResourceType::banana ){
                            continue;
                        } 
                        //when the customer arrives and i have bananas but no schweppeses, free worker, and i havent sent a workerbeforehand
                        else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() >= clients_waiting.first().data1.banana && this->getSchweppes() <  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && workers_sent.isEmpty() ) {
                            Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                            workers_sent.enqueue(worker);
                            workers_free--;
                            actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                        }
                        //when the customer arrives but i have bananas but no schweppeses, free worker and i haven't sent a worker for schweppeses
                        else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() >=  clients_waiting.first().data1.banana && this->getSchweppes() <  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && !workers_sent.isEmpty() && workers_sent.first().data2 != ResourceType::schweppes) {
                            Pair<int, ResourceType> worker( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                            workers_sent.enqueue(worker);
                            workers_free--;
                            actionHandler->onWorkerSend( clients_waiting.first().data1.arriveMinute, ResourceType::schweppes);
                        }
                        //when the customer arrives and i have bananas but no schweppeses, free worker, i have sent a worker beforehand but for schweppeses
                        //=> i skip the iteration for this customer
                         else if(clients_waiting.first().data1.arriveMinute == time && (this->getBanana() >= clients_waiting.first().data1.banana && this->getSchweppes() <  clients_waiting.first().data1.schweppes)
                        && workers_free != 0 && !workers_sent.isEmpty() && workers_sent.first().data2 == ResourceType::schweppes ){
                            continue;
                            
                        } 
                    }
                    //if the clients' waiting time runs out and he/she needs to leave
                    if(clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime == time ) {
                        //when i have enough bananas and schweppeses
                        if(clients_waiting.first().data1.banana <= this->getBanana() && clients_waiting.first().data1.schweppes <= this->getSchweppes()) {
                            this->store_bananas -= clients_waiting.first().data1.banana;
                            this->store_schweppeses -= clients_waiting.first().data1.schweppes;
                            actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime ,
                            clients_waiting.first().data1.banana, clients_waiting.first().data1.schweppes);
                            clients_waiting.dequeue();
                            size--;
                            continue;
                        } 
                        //when i dont have enough of both bananas and schweppeses
                        else if (clients_waiting.first().data1.banana > this->getBanana() && clients_waiting.first().data1.schweppes > this->getSchweppes()){
                            actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime ,
                            this->getBanana(), this->getSchweppes());
                            this->store_bananas = this->store_schweppeses = 0;
                            clients_waiting.dequeue();
                            size--;
                            continue;
                        }
                        //when i have enough bananas but not enough schweppeses 
                        else if (clients_waiting.first().data1.banana <= this->getBanana() && this->getSchweppes() < clients_waiting.first().data1.schweppes) {
                            actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime , clients_waiting.first().data1.banana,this->getSchweppes());
                            this->store_bananas -= clients_waiting.first().data1.banana;
                            this->store_schweppeses = 0;
                            clients_waiting.dequeue();
                            size--;
                            continue;
                        }
                        //when i dont have enough schweppeses but not enough bananas 
                        else if (clients_waiting.first().data1.schweppes <= this->getSchweppes() && this->getBanana() < clients_waiting.first().data1.banana) {
                            actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime ,
                            this->getBanana(),clients_waiting.first().data1.schweppes);
                            this->store_schweppeses -= clients_waiting.first().data1.schweppes;
                            this->store_bananas = 0;
                            clients_waiting.dequeue();
                            size--;
                            continue;
                        }
                        //when both of the bananas and schweppeses are 0
                        else if (this->getSchweppes() == 0 && this->getBanana() == 0) {
                            actionHandler->onClientDepart(clients_waiting.first().data2, clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime ,
                            0,0);
                            clients_waiting.dequeue();
                            size--;
                            continue;
                        }
                    }
                    //  THIS VALIDATION IS NOT NEEDED TO RUN ALL THE TESTS BUT GIVEN THE AMOUNT OF UNCHECKED CASES
                    //  I USE IT AS AN ADDITIONAL SAFETY
                    //  I AM AWARE THAT ABOVE IN THE CODE THIS VALIDATION IS MOSTLY COVERED BUT YOU CAN'T BE 100% SURE SO I WILL PLACE IT UNDER COMMENT 
                    //when the client is still waiting in the clients_waiting queue
                    if(clients_waiting.first().data1.arriveMinute < time < clients_waiting.first().data1.arriveMinute + clients_waiting.first().data1.maxWaitTime) {
                        //if in the given time i have the resources, needed i send the client away!
                        if(clients_waiting.first().data1.banana <= this->getBanana() && clients_waiting.first().data1.schweppes <= this->getSchweppes()) {
                            this->store_bananas -= clients_waiting.first().data1.banana;
                            this->store_schweppeses -= clients_waiting.first().data1.schweppes;
                            actionHandler->onClientDepart(clients_waiting.first().data2, time ,
                            clients_waiting.first().data1.banana, clients_waiting.first().data1.schweppes);
                            clients_waiting.dequeue();
                            size--;
                        }
                    }
                    size--;
                    clients_waiting.enqueue(clients_waiting.first());
                    clients_waiting.dequeue();
                }
            }
            time++;
        }
    }

    inline int getBanana() const  override{
        return this->store_bananas;
    }
    inline int getSchweppes() const override {
        return this->store_schweppeses;
    }
    ~MrazMar() override {
        
        this->workers_sent.~LinkedQueue();
        this->clients_waiting.~LinkedQueue();
        this->clients_queue.~LinkedQueue();
        this->time = this->store_bananas = this->store_schweppeses = this->workers_free = 0;
    }
};


Store *createStore() {
    MrazMar* to_be_returned = new MrazMar();    
    return to_be_returned;
}

//====================================
//the main 

// int main() {

//     Store* myStore = createStore();
//     AH_Implementation* a1 = new AH_Implementation();
//     myStore->setActionHandler(a1);
//     myStore->init(3,0,0);
//     int clients_count;
//     std::cin >> clients_count;
//     Client* clients = new Client[clients_count];
//     for (size_t i = 0; i < clients_count; i++)
//     {
//         int arriveMin, bananas,schweppeses,maxWaitTime;
//         std::cin >> arriveMin >> bananas >> schweppeses >> maxWaitTime;
//         Client current{arriveMin,bananas,schweppeses,maxWaitTime};
//         clients[i] = current;
//     }
    
//     myStore->addClients(clients, clients_count);
//     myStore->advanceTo(100);
//     return 0;
// }