#include <iostream>
#include <vector>
using namespace std;

const int m=4;

struct mtnode
{
  int tag;
  vector<mtnode*> child;
  vector<int> data;
};

typedef mtnode* mtptr;

mtptr createNode(int n)
{
  mtptr nn=new mtnode;

  nn->child.push_back(NULL);
  nn->child.push_back(NULL);
  nn->data.push_back(n);
  nn->tag=1;
  return nn;
}

void addData(mtptr &T, int n)
{
  if(T==NULL)T=createNode(n);
  else
  {
    if(T->tag<m && T->data[T->data.size()-1]<n)
    {
      T->tag++;
      T->data.push_back(n);
      T->child.push_back(NULL);
    }
    else if(T->data[0]>n)
    {
      addData(T->child[0], n);
    }
    else
    {
      for(int i=0; i<T->data.size(); i++)
      {
        if(T->data[i]<n && T->data[i+1]>n)addData(T->child[i+1], n);
      }
    }
  }
}

void print_tree(mtptr T)
{
  if(T==NULL)return;
  else
  {
    int i=0;
    for(i=0; i<T->data.size(); i++)
    {
      print_tree(T->child[i]);
      cout << T->data[i] << " ";
    }
    i=T->data.size();
    print_tree(T->child[i]);
  }
}

int main()
{
  mtptr root=NULL;
  int n;
  char ans='y';
  while(ans=='y')
  {
    cin >> n;
    addData(root, n);
    cin >> ans;
  }
  print_tree(root);
  return 0;
}
