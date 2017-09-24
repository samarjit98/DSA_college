#include <iostream>
using namespace std;

struct bstnode
{
  int data;
  bstnode* left;
  bstnode* right;
};
typedef bstnode* bstptr;

bstptr createNode(int n)
{
  bstptr nn=new bstnode;
  nn->data=n;
  nn->left=NULL; nn->right=NULL;
  return nn;
}

void insert(bstptr &T, int n)
{
  if(T==NULL)T=createNode(n);
  else if(T->data<n)insert(T->right, n);
  else insert(T->left, n);
}

void extremes(bstptr T, int &min, int &max, int curr)
{
  if(T==NULL)return;

  if(min>curr)min=curr;
  if(max<curr)max=curr;
  extremes(T->right, min, max, curr+1);
  extremes(T->left, min, max, curr-1);
}

void specific_level(bstptr T, int curr, int req)
{
  if(T==NULL)return;
  else if(curr==req)
  {
    cout << T->data << " ";
    specific_level(T->left, curr-1, req);
    specific_level(T->right, curr+1, req);
  }
  else
  {
    specific_level(T->left, curr-1, req);
    specific_level(T->right, curr+1, req);
  }
}

void print_vertical_order(bstptr T)
{
  int min=0, max=0;
  extremes(T, min, max, 0);
  for(int i=min; i<=max; i++)
  {
    specific_level(T, 0, i);
    cout << endl;
  }
}

int main()
{
  bstptr root=NULL;
  int n;
  cin >> n;
  while(n!=-1)
  {
    insert(root, n);
    cin >> n;
  }
  print_vertical_order(root);
  return 0;
}
