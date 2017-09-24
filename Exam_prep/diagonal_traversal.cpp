#include <iostream>
#include <queue>
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

void diagonal_traversal(bstptr &T)
{
  queue<bstptr> q;
  q.push(T);
  while(!q.empty())
  {
    int t=q.size();
    while(t--)
    {
      bstptr tmp=q.front();
      q.pop();
      while(tmp!=NULL)
      {
        cout << tmp->data << " ";
        if(tmp->left!=NULL)q.push(tmp->left);
        tmp=tmp->right;
      }
    }
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
  diagonal_traversal(root);
  return 0;
}
