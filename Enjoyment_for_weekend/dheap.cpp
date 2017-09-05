#include <iostream>
using namespace std;

struct dheap
{
  int data;
  dheap* parent;
  dheap** arr;
};

typedef dheap* dptr;

dptr createNode(int data, int d)
{
  dptr newNode=new dheap;
  newNode->data=data;
  newNode->parent=NULL;
  newNode->arr=new dptr[d];
  for(int i=0; i<d; i++)newNode->arr[i]=NULL;

  return newNode;
}

void createHeap(dptr &root, int d)
{
  cout << "Enter data:-"; int n; cin >> n;
  root=createNode(n, d);
  for(int i=0; i<d; i++)
  {
    cout << "Does " << n << " have " << i << " child?"; char ans; cin >> ans;
    if(ans=='y')createHeap(root->arr[i], d);

    if(root->arr[i]!=NULL)root->arr[i]->parent=root;
  }
}

void printHeap(dptr root, int d)
{
  if(root==NULL)return;
  else
  {
    cout << root->data << " ";
    for(int i=0; i<d; i++)printHeap(root->arr[i], d);
  }
}

int main()
{
  int d;
  cout << "Enter standard d value:"; cin >> d;
  dptr root=NULL;
  createHeap(root, d);
  printHeap(root, d);
  return 0;
}
