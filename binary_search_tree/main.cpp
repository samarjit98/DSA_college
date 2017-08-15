#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node* newNode(int n)
{
    Node *tmp=new Node;
    tmp->key=n;
    tmp->left=NULL;
    tmp->right=NULL;

    return tmp;
}

void printInorder(Node *n)
{
    if(n==NULL)return;

    printInorder(n->left);

    cout << n->key << " ";

    printInorder(n->right);
}

Node* insertBST(Node *n, int data)
{
    if(n==NULL)
    {
        return newNode(data);
    }

    if(data>n->key)n->right=insertBST(n->right, data);
    else n->left=insertBST(n->left, data);

    return n;
}

int main()
{
    Node *root=insertBST(root, 120);
    for(int i=100; i<=115; i++)insertBST(root, i);

    printInorder(root);

    return 0;
}
