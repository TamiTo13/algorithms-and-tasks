#include <iostream>
#include <exception>

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};

struct Interval
{
    int i;
    int j;
};

template<typename T>
void printList(const Node<T>* head)
{
    while(head)
    {
        std::cout<<head->data<<" ";
        head = head->next;
    }
}


/* template<typename T>
void reverse(Node<T>* list, int i, int j)//O(N) space complexity, O(n) time
{
    Node<T>* ptr = list;
    int counter = 0;
    int current = 0;
    T* smallList = new T(j - i);
    while(counter != j) 
    {
        if(counter >= i)
        {
            smallList[current++] = ptr->data;
        }

        ptr = ptr->next;
        counter++;
    }

    counter = 0;
    while(counter != j)
    {
        if(counter >= i)
        {
            ptr->data = smallList[current--];
        }

        ptr = ptr->next;
        counter++;
    }
} */


void reverse(Node<int>* list, int i, int j) //O(1) space, O(n) time
{
    Node<int>* ptr = list;
    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    int counter = 0;
    while(counter <= j+1)
    {
        if(counter == i-1) 
                    head = ptr;

        if(counter == j+1)
        {
             tail = ptr;
        }
        counter++;
        ptr = ptr->next;
    }

    Node<int>* prev = tail;
    Node<int>* curr = head->next;
    Node<int>* next = nullptr;
    for(int t= 0; t<=j-i; t++)
    {
            Node<int>* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
    }
    head->next = prev;

    delete ptr;
    delete head;
    delete tail;
    delete prev;
    delete curr;
    delete next;
}


void reverseSublists(Node<int>* list, Node<Interval>* intervals)
{
    Node<int>* ptr = list;
    int length = 0;
    while (ptr)
    {
        length++;
        ptr = ptr->next;
    }

    while (intervals)
    {
        if(intervals->data.i<0 || 
            intervals->data.i >= intervals->data.j ||
            intervals->data.j>length )
            {
                //throw new IllegalArgumentException(); ->
            }
        
        reverse(list, intervals->data.i, intervals->data.j);
        intervals = intervals->next;
    }

    delete ptr;
}



int main()
{
    Node<int>* a = new Node<int>{11, 
                        new Node<int>{4, 
                        new Node<int>{3,
                        new Node<int>{7,
                        new Node<int>{13,
                        new Node<int>{4,
                        new Node<int>{5,nullptr}}}}}}};
    reverse(a, 1, 3);
    printList(a); 

    delete a;
}