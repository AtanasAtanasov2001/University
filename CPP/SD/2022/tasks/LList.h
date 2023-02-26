#pragma once
template<typename T>
class LList{

    private:
    struct Node{
        T data;
        Node* next;
        Node() = default;
        Node(T _data, Node* _next):data(_data),next(_next){};
    } *first;

    public:
    LList();
    LList(const LList<T> &other);
    ~LList();
    LList& operator=(const LList<T> &other) ;

    bool push(T value);
    bool pop();
    const Node& top() const;
    void print() const;
    unsigned int size() const;
};





