#include <iostream>


struct Node {
    int data;
    Node* l;
    Node* r;
    Node(int _data) : data(_data), l(nullptr), r(nullptr) {};
    Node(int _data, Node* _l, Node* _r) : data(_data), l(_l), r(_r) {};
};

int height(Node* root) {
    if(!root)
        return 0;
    
    return 1 + std::max(height(root->l), height(root->r));
}

size_t myAbs (int a) {
    return a < 0 ? -a : a;
}

bool isHeightBalanced (Node* root) {
    return myAbs(height(root->l) - height(root->r)) <= 1;  
}

bool isBalanced (Node* root) {

    if(!root) return true;

    if(!root->l || !root->r) {
        return isHeightBalanced(root) && isBalanced(root->l) && isBalanced(root->r);
    }
    else {
        return isBalanced(root->l) && isBalanced(root->r);
    }
}


Node* mirrorTree(Node* root) {
    if(!root) 
        return nullptr;
    Node* current = new Node(root->data);
    current->l= mirrorTree(root->r);
    current->r = mirrorTree(root->l);

    return current;
}

void printInOrder(Node*& root)
{
    if(root) {
        printInOrder(root->l);
	std::cout<<root->data<<" ";
        printInOrder(root->r);
        std::cout<<std::endl;
        
    }
}

int main() {
    Node* tree = new Node{1, 
                        new Node{2,
                            new Node{4, 
                               new Node{7, nullptr, nullptr}, nullptr},
                            new Node{5, nullptr, nullptr} }, 
                        new Node{3,
                            new Node{6, nullptr, nullptr}, nullptr}};


    //printInOrder(tree);
    Node * nz = mirrorTree(tree);
    printInOrder( nz );
}