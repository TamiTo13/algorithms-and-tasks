#include <iostream>

struct Node
{
    int data;
    Node* next;
};


void printList( const Node* pHead )
{
    while ( pHead != nullptr )
    {
        std::cout << pHead->data << ' ';
        pHead   = pHead->next;
    }
}


void kReverse(Node*& head, int k)
{
    Node* curr = head;
    size_t len = 0;
    while(curr)
    {
        len++;
        curr = curr->next; 
    }
    unsigned iterate = len / k;

    Node* attach = head;
    for (int i = 0; i<iterate;i++)
    {
        //std::cout<<iterate;
        Node* prev = nullptr;
        curr = attach;
        Node* tmp = nullptr;
        for (int i = 0; i<k;i++)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        head = prev;
        //printList(head);
    }
}

/*
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
*/




int main()
{
     Node*   pList3  = 
        new Node { 1,
            new Node { 2,
                new Node { 3,
                    new Node { 4, 
                        new Node {5,
                            new Node {6 ,
                                new Node{7, 
                                    new Node{8, nullptr}}} }
                        }
                    }
            }
        };

        kReverse(pList3, 8);
        printList(pList3);
}

