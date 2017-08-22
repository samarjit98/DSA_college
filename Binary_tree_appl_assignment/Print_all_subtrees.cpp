#include <iostream>
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

void preorder(btptr root)
{
  if(root!=NULL)
  {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void print_all_subtrees(btptr root)
{
  if(root==NULL)return;
  
  if(root!=NULL){preorder(root); cout << endl;}

  if(root->left!=NULL){print_all_subtrees(root->left); cout << endl;}

  if(root->right!=NULL){print_all_subtrees(root->right); cout << endl;}
}

int main()
{
  btptr head=NULL;
  create_init_tree(head);
  cout << endl;
  print_all_subtrees(head);
  return 0;
}
