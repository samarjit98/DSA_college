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
  btptr root=NULL;
  create_init_tree(root);
  cout << endl;
  //order_store(root);
  printAsItIs(root);
  return 0;
}
