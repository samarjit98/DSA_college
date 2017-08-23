#include <iostream>
#include <queue>
using namespace std;

struct btnode
{
  btnode* left;
  int data;
  btnode* right;
};

typedef btnode* btptr;

btptr createBTNode(int n)
{
  btptr newNode=new btnode;
  newNode->data=n; newNode->left=NULL; newNode->right=NULL;
  return newNode;
}

void create_init_tree(btptr &root)
{
    cout << "Enter data:"; int n; cin >> n;
    root=createBTNode(n);
    cout << "Does " << n << " have a left child:"; char ans; cin >> ans;
    if(ans=='y')create_init_tree(root->left);
    cout << "Does " << n << " have a right child:"; cin >> ans;
    if(ans=='y')create_init_tree(root->right);
}

void reverse_tree(btptr root, btptr &newtree)
{
  if(root==NULL)return;
  else
  {
    newtree=createBTNode(root->data);
    reverse_tree(root->right, newtree->left);
    reverse_tree(root->left, newtree->right);
  }
}

void printAsItIs(btptr root, int sp=0)
{
  if(root==NULL)return;

  sp+=10;

  printAsItIs(root->right, sp); cout << endl;
  for(int i=10; i<=sp; i++)cout << " "; cout << root->data; cout << endl;
  printAsItIs(root->left, sp);
}

int main()
{
  btptr head=NULL;
  create_init_tree(head);
  btptr head2=NULL;
  reverse_tree(head, head2);
  printAsItIs(head); cout << endl;
  printAsItIs(head2);
}
