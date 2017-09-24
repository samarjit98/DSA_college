#include <iostream>
#include <queue>
#include <stack>
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

void revLevel(bstptr T)
{
  queue<bstptr> q;
  stack<bstptr> s;
  q.push(T);
  while(!q.empty())
  {
    bstptr tmp=q.front(); q.pop();
    s.push(tmp);
    if(tmp->left!=NULL)q.push(tmp->left);
    if(tmp->right!=NULL)q.push(tmp->right);
  }
  while(!s.empty())
  {
    bstptr tmp=s.top();
    cout << tmp->data << " "; s.pop();
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
  revLevel(root);
  return 0;
}
