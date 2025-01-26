#include <iostream>
#include "PersonalStack.h"

template<typename T>
bool MyStack<T>::empty() const
{
    return topPtr == NULL;
}

template<typename T>
void MyStack<T>::push(const T& obj)
{
    Node<T>* newElement = new Node<T>;
    newElement->data = obj;
    newElement->next = topPtr;
    topPtr = newElement;
    //std::cout<<"push!";
    //std::cout<<topPtr->data;

}

template<typename T>
T MyStack<T>::pop()
{
    if(empty())
    {
        std::cerr<<"Its empty";
        return T();
    }

    Node<T>* temp = topPtr;
    topPtr =  topPtr->next;
    T x = temp->data;
    delete temp;

    return x;
}

template<typename T>
const T MyStack<T>::top() const
{
    if(empty())
    {
        std::cerr<<"faida si brat";
        return T();
    }
    return topPtr->data;
}


template<typename T>
void MyStack<T>::clear()
{
    while(!empty())
    {
        pop();
    }
}

template<typename T>
void MyStack<T>::copy(Node<T> *other)
{
    if(other == nullptr)       //other.topPtr == null
    {
        return;
    }

       copy(other->next);
       push(other->data);
}

template<typename T>
void MyStack<T>::copy_wrapper(MyStack<T> const& stack)
{
    topPtr = nullptr;
    copy(stack.topPtr);
}

template<typename T>
MyStack<T>::MyStack(MyStack<T> const& other)
{
    copy_wrapper(other);
}

template<typename T>
MyStack<T>&  MyStack<T>::operator=(const MyStack<T>& other)
{
    if(this != &other)
    {
        clear();
        copy_wrapper(other);
    }

    return *(this);
}

template<typename T>
MyStack<T>::~MyStack()
{
    clear();
}

