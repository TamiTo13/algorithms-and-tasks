#pragma once
#include "Node.h"

template <typename T>
class MyStack
{
    Node<T>* topPtr;

    void clear();
    void copy(Node<T> *);
    void copy_wrapper(MyStack<T> const&);

    public:
        MyStack(): topPtr(nullptr){};
        MyStack(MyStack const&);
        MyStack<T>& operator=(MyStack<T> const&);
        ~MyStack();

    T pop();
    void push(const T&);
    bool empty() const;
    const T top() const;
    //const T& peek(int index);
};