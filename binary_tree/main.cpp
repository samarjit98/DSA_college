#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* newNode(int n)
{
    node* nm=new node;
    nm->data=n;
    nm->left=NULL;
    nm->right=NULL;

    return nm;
}

void printPostOrder(node* n)
{
    if(n==NULL)return;

    printPostOrder(n->left);

    printPostOrder(n->right);

    printf("%d ", n->data);
}

void printPreOrder(node* n)
{
    if(n==NULL)return;

    printf("%d ", n->data);

    printPreOrder(n->left);

    printPreOrder(n->right);
}

void printInOrder(node* n)
{
    if(n==NULL)return;

    printInOrder(n->left);

    printf("%d ", n->data);

    printInOrder(n->right);
}

int main()
{
    node* root=newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    printPostOrder(root);
    cout << endl;
    printPreOrder(root);
    cout << endl;
    printInOrder(root);

    return 0;
}
