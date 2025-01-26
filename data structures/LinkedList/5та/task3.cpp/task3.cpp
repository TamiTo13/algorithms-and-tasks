#include <iostream>


struct Node
{
    int fpData;
    Node* fpNext;
};




void insertAfter(Node* pNode)
{
    if (pNode == nullptr) return;


}

void deleteAfter(Node* pNode)
{
    if ( pNode == nullptr || pNode->fpNext == nullptr )
        return;

    Node*   pToDel          = pNode->fpNext;
            pNode->fpNext   = pNode->fpNext->fpNext;
    delete  pToDel;
}

void printList( const Node* pHead )
{
    while ( pHead != nullptr )
    {
        std::cout << pHead->fpData << ' ';
        pHead   = pHead->fpNext;
    }
}

void removeSumZero(Node* head)
{
    Node* iter = head;
    Node* headSum = new Node{head->fpData, nullptr};
    iter = iter->fpNext;
    Node* ptrSum = headSum;
    while(iter)
    {
        ptrSum->fpNext = new Node{iter->fpData + ptrSum->fpData, nullptr};
        iter = iter->fpNext;
        ptrSum = ptrSum->fpNext;
    }


    Node* start = head;
    while(headSum)
    {
        int current = headSum->fpData;
        //std::cout<<current<<", ";
        ptrSum = headSum->fpNext;
        int toDel = 1;
        while(ptrSum)
        {
            if(current == ptrSum->fpData)
            {
                for(int i =0; i < toDel; i++)
                {
                    deleteAfter(head); //MAAMA VI DEEBA
                    deleteAfter(headSum);
                }
            }
            ptrSum = ptrSum->fpNext;
            toDel++;
        }
        headSum = headSum->fpNext;
        head = head->fpNext;
       //std::cout<<headSum->fpData;
    }
    printList(start);
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

        Node*   pList3  = 
        new Node { 3,
            new Node { 4,
                new Node { 2,
                    new Node { -6, 
                        new Node {1,
                            new Node {2 ,
                                new Node{5, 
                                    new Node{-7, nullptr}}} }
                        }
                    }
            }
        };
    

        removeSumZero(pList3);
}