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

void delete_from_tree(btptr &root, int k)
{
  if(root==NULL)return;
  else if(root->right==NULL && root->left==NULL && root->data==k)
  {
    root=NULL;
  }
  else if(root->data==k && root->left!=NULL)
  {
    btptr &tmp=root->left;
    while(tmp->right!=NULL)tmp=tmp->right;
    root->data=tmp->data;
    delete_from_tree(tmp, tmp->data);
  }
  else if(root->data==k && root->right!=NULL)
  {
    btptr &tmp=root->right;
    while(tmp->left!=NULL)tmp=tmp->left;
    root->data=tmp->data;
    delete_from_tree(tmp, tmp->data);
  }
  else if(root->data!=k)
  {
    if(root->right!=NULL)delete_from_tree(root->right, k);
    if(root->left!=NULL)delete_from_tree(root->left, k);
  }
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
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter to delete:"; cin >> n;
    delete_from_tree(root, n);
    order(root);
    cout << "MORE?"; cin >> ans;
  }
  return 0;
}
