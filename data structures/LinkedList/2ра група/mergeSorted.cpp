#include <iostream>

struct Node
{
    int data;
    Node* next;
};


void deleteList(Node* head)
{
    while(head)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
        delete temp;
    }
}

/*Node* mergeLists(Node* head1, Node* head2)
{
    Node* result = nullptr;
    if (head1->data < head2->data) {
        result = new Node{head1->data, nullptr};
        head1 = head1->next;
    }
    else {
        result->data = head2->data;
        head2 = head2->next;
    }

    Node* current = result;
    Node* ahead = result;
    while(head1 && head2)
    {
        if (head1->data < head2->data)
        {
            ahead = new Node{head1->data, nullptr};
            head1 = head1->next;
        }
        else
        {
            ahead = new Node{head2->data, nullptr};
            head2 = head2->next;
        }
        current->next = ahead;
        current = current->next; 
    }

    while(head1)
    {
        ahead = new Node{head1->data, nullptr};
        head1 = head1->next;
        current->next = ahead;
        current = current->next;
    }

    while(head2)
    {
        ahead = new Node{head2->data, nullptr};
        head2 = head2->next;
        current->next = ahead;
        current = current->next;
    }

    return result;
} */

Node* mergeLists( Node* head1, Node* head2 )
{
	Node* resultList = nullptr;
	if ( head1 && head2 )
	{
		if ( head1->fData < head2->fData )
		{
			resultList = new Node { head1->fData, nullptr };
			head1 = head1->fpNext;
		}
		else
		{
			resultList = new Node { head2->fData, nullptr };
			head2 = head2->fpNext;
		}
	}
	Node* aheadIt = resultList;
	Node* currentIt = resultList;
	while ( head1 != nullptr && head2 != nullptr )
	{
		if ( head1->fData < head2->fData )
		{
			aheadIt = new Node { head1->fData, nullptr };
			head1 = head1->fpNext;
		}
		else
		{
			aheadIt = new Node { head2->fData, nullptr };
			head2 = head2->fpNext;
		}
		currentIt->fpNext = aheadIt;
		currentIt = currentIt->fpNext;
	}
	
	while ( head1 )
	{
		aheadIt = new Node { head1->fData, nullptr };
		currentIt->fpNext = aheadIt;
		currentIt = currentIt->fpNext;
		head1 = head1->fpNext;
	}
	while ( head2 )
	{
		aheadIt = new Node { head2->fData, nullptr };
		currentIt->fpNext = aheadIt;
		currentIt = currentIt->fpNext;
		head2 = head2->fpNext;
	}

	return resultList;
}

void printList( Node* head )
{
	while ( head )
	{
		Node* temp = head->next;
		std::cout << head->data << " ";
		head = temp;
	}
	std::cout << std::endl;
}

int main()
{
	Node* head1 = new Node{ 2
				, new Node{ 2
				, new Node{ 4
				, new Node{ 7
				, new Node{ 11
				, new Node{ 12
				, new Node{ 17
				, new Node{ 21, nullptr } } } } } } } };

	Node* head2 = new Node{ -4
				, new Node{ -3
				, new Node{ -1
				, new Node{ 0
				, new Node{ 0
				, new Node{ 5
				, new Node{ 7
				, new Node{ 10
				, new Node{ 17
				, new Node{ 37, nullptr } } } } } } } } } };

	std::cout << "First list: ";
	printList( head1 );
	std::cout << "Second list: ";
	printList( head2 );

	std::cout << "Merging..." << std::endl;
	Node* newList = mergeLists( head1, head2 );

	std::cout << "The result list is: " << std::endl;
	printList( newList );

	deleteList( head1 );

	return 0;
}


  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
	    // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        ListNode *curr = ptr;
        
		// till one of the list doesn't reaches NULL
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
		
		// adding remaining elements of bigger list.
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
       
    }