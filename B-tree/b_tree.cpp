#include <iostream>
#include <algorithm>
using namespace std;

const int d=1;

struct btnode
{
  struct elements
  {
    int data;
    btnode* link;
  } ele[2*d+1];
  int k;
  btnode* f;
  btnode* pptr;
  bool leaf;

  static bool func(elements e1, elements e2)
  {
    return e1.data<e2.data;
  }
};

typedef btnode* btptr;

btptr root;

btptr createNode(int n)
{
  btptr nn=new btnode;
  nn->ele[0].data=n;
  nn->ele[0].link=NULL;
  nn->f=NULL;
  nn->k=1;
  nn->leaf=true;
  nn->pptr=NULL;

  return nn;
}

void insert(int n, btptr &T);
void Node_split(int n, btptr &T)
{
    if(T->pptr==NULL)
    {
      btptr sec=new btnode;
      sec->f=NULL;
      T->ele[2*d].data=n;
      T->ele[2*d].link=NULL;
      sort(T->ele, T->ele+(2*d+1), T->func);
      T->k=d;
      for(int i=0; i<d; i++)
      {
        sec->ele[i]=T->ele[d+1+i];
      }
      sec->k=d;
      btptr par=new btnode;
      par=createNode(T->ele[d].data);
      par->f=T;
      par->ele[0].link=sec;
      for(int i=d; i<2*d+1; i++)T->ele[i].link=NULL;
      root=par;
    }
    else
    {
      btptr sec=new btnode;
      sec->f=NULL;
      T->ele[2*d].data=n;
      T->ele[2*d].link=NULL;
      sort(T->ele, T->ele+(2*d+1), T->func);
      T->k=d;
      for(int i=0; i<d; i++)
      {
        sec->ele[i]=T->ele[d+1+i];
      }
      sec->k=d;
      T->pptr->leaf=true;
      insert(T->ele[d].data, T->pptr);
      T->pptr->ele[0].link=sec;
      T->pptr->leaf=false;
      for(int i=d; i<2*d+1; i++)T->ele[i].link=NULL;
    }
}

void insert(int n, btptr &T)
{
  if(T==NULL)
  {
    T=createNode(n);
  }
  else if(T->leaf)
  {
    if(T->k<2*d)
    {
      T->ele[T->k].data=n;
      T->ele[T->k].link=NULL;
      T->k++;
      sort(T->ele, T->ele+T->k, T->func);
    }
    else
    {
      Node_split(n, T);
      return;
    }
  }
  else
  {
    if(T->ele[0].data>n)insert(n, T->f);
    else
    {
      for(int i=0; i<T->k; i++)if(T->ele[i].data<n)insert(n, T->ele[i].link);
    }
  }
}

void inorder(btptr T)
{
  if(T==NULL)return;
  else
  {
    inorder(T->f);
    for(int i=0; i<T->k; i++)
    {
      cout << T->ele[i].data << " ";
      inorder(T->ele[i].link);
    }
  }
}

int main()
{
  root=NULL;
  char ans='y';
  while(ans=='y')
  {
    int n; cin >> n;
    insert(n, root);
    cin >> ans;
  }
  inorder(root);
  return 0;
}
