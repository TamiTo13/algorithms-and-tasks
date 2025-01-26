#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
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

void deleteAfter(Node<int>* head)
{
    if(head == nullptr) return;

    Node<int>* toDel = head->next;
    head->next = toDel->next;
    delete toDel;
}

bool calculate(Node<int>* prev, Node<int>* next, int curr)
{
    return curr == prev->data + next->data;
}


bool makeTotal(Node<int>* head)
{
    Node<int>* ptr = head;
    int length = 0;
    while(ptr)
    {
        length++;
        ptr = ptr->next;
    }
    if(length < 3) return false;

    ptr = head->next;
    Node<int>* prev = head;
    Node<int>* next = nullptr; // ptr->nexy
    bool returnVal = true;
    while(ptr->next)
    {
        next = ptr->next;
        if(!calculate(prev, next, ptr->data))
        {
            //std::cout<<"ss";
            returnVal = false;
            break;
        }
        ptr = ptr->next;
        prev = prev->next;
    }

    
    if(!returnVal)
    {
        prev = head;
        next = nullptr;
        ptr = head->next;
        while(ptr->next)
        {
            next = ptr->next;
            if(!calculate(prev, next, ptr->data))
            {
                deleteAfter(prev);
            }
            ptr = ptr->next;
            prev = prev->next;
                
        }
    }

    delete prev;
    delete ptr;
    delete next;

    return returnVal;

}

int main()
{

        Node<int>* a = new Node<int>{1, 
                        new Node<int>{4, 
                        new Node<int>{-5,
                        new Node<int>{-1,
                        new Node<int>{4, nullptr}}}}};
    //no time to check
    //O(1) space complexity, O(n) time

    std::cout<<makeTotal(a);
    delete a;
}