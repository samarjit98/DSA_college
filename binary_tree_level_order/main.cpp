#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int n)
{
    Node* nm=new Node;
    nm->data=n;
    nm->left=NULL;
    nm->right=NULL;

    return nm;
}

void printLevelOrder(Node *n)
{
    if(n==NULL)return;

    queue<Node *> q;

    q.push(n);

    while(q.empty()==false)
    {
        Node *tmp=q.front();
        cout <<  tmp->data << " ";
        q.pop();

        if(tmp->left!=NULL)q.push(tmp->left);
        if(tmp->right!=NULL)q.push(tmp->right);
    }
}

int main()
{
    Node *root=newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
	root->right->right->right=newNode(8);

    printLevelOrder(root);

    return 0;
}
