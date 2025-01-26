#include <iostream>

template <typename T>
struct TNode{
    T data;
    TNode* left;
    TNode* right;

    TNode(const T& _data) : data(_data), left(NULL), right(NULL) { }
};

template <typename T>
bool isLeaf(const TNode<T>* node) {
    return node && !node->left && !node->right;
}


int getHeight(const TNode<int>* root) {
    
    if(!root){
        return 0;
    }

    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

template <typename T>
void deleteTree( TNode<T>*& root )
{
	if ( root )
	{
		deleteTree( root->left );
		deleteTree( root->right );
		delete root;
		root = nullptr;
	}
}

template <typename T>
void printInOrder(const TNode<T>*& root)
{
    if(root) {
        printInOrder(root->left);
        printInOrder(root->right);
        std::cout<<root->data;
    }
}

template <typename T, class F>
void map_Tree(const TNode<T>*& root, const F& f) {
    if(root) {
        map_Tree(root->left);
        map_Tree(root->right);
        f(root->data);
    }
}

void printLevelOrder(TNode<int>* root)
{
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(TNode<int>* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        std::cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int main() {
    TNode<int>* root = new TNode<int>(1);
 
    root->left = new TNode<int>(2);
    root->right = new TNode<int>(3);
    root->left->left = new TNode<int>(4);
    //root->left->right = new TNode<int>(5);
    root->left->left->right = new TNode<int>(5);
    root->left->left->right->right = new TNode<int>(5);
    root->left->left->right->right->left = new TNode<int>(5);
    
    std::cout<<std::max(1,2);


}

TNode* sortedArrayToBST(int arr[],
                        int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);
 
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);
 
    return root;
}