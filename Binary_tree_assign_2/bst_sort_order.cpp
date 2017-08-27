#include <iostream>
#include <vector>
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

void insert_into_tree(btptr &root, int n)
{
    if(root==NULL)root=createBTNode(n);
    else if(root->data<n)insert_into_tree(root->right, n);
    else insert_into_tree(root->left, n);
}

void order(btptr root)
{
  if(root!=NULL)
  {
    order(root->left);
    cout << root->data << " ";
    order(root->right);
  }
}

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> a;
  while(n--)
  {
    cin >> tmp; a.push_back(tmp);
  }

  btptr root=NULL;
  for(int i=0; i<a.size(); i++)insert_into_tree(root, a[i]);
  order(root);
  return 0;
}
