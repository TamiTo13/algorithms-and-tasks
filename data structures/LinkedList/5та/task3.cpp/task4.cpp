#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void insertAfter(Node* insert, Node* inserted)
{
    if(inserted == nullptr)
    {
        insert->next=nullptr;
        return;
    }
    if(insert == nullptr) {
        std::cerr<<"Na maykati putkata";
        return;
    };

    Node* tmp = inserted;
    //std::cout<<inserted->next->data;
    inserted = inserted->next;
    tmp->next = insert->next;
    insert->next = tmp;
}

Node* findMid(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseList(Node* head)
{
    Node* prev = nullptr;
    while(head)
    {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    //std::cout<<prev->data;
    return prev;
}

void printList( const Node* pHead )
{
    while ( pHead != nullptr )
    {
        std::cout << pHead->data << ' ';
        pHead   = pHead->next;
    }
}
 
void reorder(Node* head)
{
    Node* ptrHead = head;
    Node* mid = findMid(head);
    Node* secondHead = reverseList(mid);
    //printList(secondHead);
    while(ptrHead)
    {
        insertAfter(ptrHead, secondHead);
        //std::cout<<head->data<<" "<<secondHead->data<<" ";
        //std::cout<<secondHead->data;
        ptrHead = ptrHead->next->next;
    }
    //delete mid;
    //delete secondHead;
}


int main()
{
    Node*   pList2   = 
        new Node { 3,
            new Node { 4,
                new Node { 2,
                    new Node { -6, nullptr }
                        }
                    }
        };

    reorder(pList2);
    printList(pList2);
    
}