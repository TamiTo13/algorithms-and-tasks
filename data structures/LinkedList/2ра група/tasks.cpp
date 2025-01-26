#include <iostream>

struct Node
{
    int data;
    Node* next;
};

template<typename T>
struct Block
{
    T data;
    Block<T>* next;
};


void insertAfter(Node* link, int num)
{
    if(link == NULL) return;

    Node* newNode = new Node{num, link->next};
    link->next = newNode;
}

void deleteAfter(Node* link)
{
    if ( link == nullptr || link->next == nullptr )
        return;

    Node*   pToDel          = link-> next;
            link->next   = link->next->next;
    delete  pToDel;
}

void delete_After(Node* link)
{
   // if ( link == nullptr || link->next == nullptr )
        return;

    Node*   pToDel          = link-> next;
            link->next   = link->next->next;
    delete  pToDel;
}

template<typename T>
bool compareK(Block<T>* first, Block<T>* second, unsigned k)
{
    while (first != nullptr && second != nullptr
           && first->data == second->data 
           && k != 0)
    {
        first = first->next;
        second = second->next;
        k--;
    }
    
    return k==0;
}

template<typename T>
bool dupsub(Block<T>* head, unsigned k)
{
    while(head != nullptr)
    {
        Block<T>* ahead = head->next;
        while(ahead != nullptr)
        {
            if(compareK(head,ahead,k)) return true;
            ahead = ahead->next;
        }
        head->next;
    }

    return false;

}

void removedups(Node* head)
{
    Node* ahead = head->next;
    while(ahead)
    {
     if(head->data == ahead->data)
     {
        deleteAfter(head);
     }
     else
     {
        head = head->next;
     }

    ahead = head->next;
    }
}

void printList( const Node* pHead )
{
    while ( pHead != nullptr )
    {
        std::cout << pHead->data << ' ';
        pHead   = pHead->next;
    }
}

void clearList( Node*& pHead )
{
    // pHead is a reference so we can set it to nullptr
    // after the list has been cleared

    while ( pHead )
    {
        Node*   pToDel  = pHead;
                pHead   = pHead->next;
        delete  pToDel;
    }
}


void mirror(Node* head)
{
    if(head == NULL) return;

    Node* last = head->next;
    while(last->next)
    {
        last = last->next;
    }

    while(head != last->next)
    {
        insertAfter(last, head->data);
        head = head->next;
    }
}


int main()
{
     Node*   pList2   = 
        new Node { 1,
            new Node { 2,
                new Node { 2,
                    new Node { 5, 
                        new Node { 7,
                            new Node { 7, nullptr }
                        }
                    }
                }
            }
        };
    
    std::cout << "removedups: \t";
    //printList( pList2 );
    removedups( pList2 );
    printList( pList2 );
    std::cout << '\n';
    clearList(pList2);
    return 0;
}