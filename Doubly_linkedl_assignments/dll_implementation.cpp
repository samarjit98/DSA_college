#include <iostream>
using namespace std;

struct dllNode
{
  dllNode* left;
  int data;
  dllNode* right;
};

dllNode* createNode(int n)
{
  dllNode* newNode=new dllNode;
  newNode->left=NULL; newNode->right=NULL;
  newNode->data=n;

  return newNode;
}

void addNode(dllNode* &head, int n)
{
  if(head==NULL)
  {
    head=createNode(n); return;
  }

  dllNode* tmp=head;
  while(tmp->right!=NULL)
  {
    tmp=tmp->right;
  }
  tmp->right=createNode(n);
  tmp->right->left=tmp;
}

int main()
{
  dllNode* head=NULL;
  for(int i=1; i<=10; i++)addNode(head, i);

  dllNode* tmp=head;
  while(tmp->right!=NULL)
  {
    cout << tmp->data << " "; tmp=tmp->right;
  }
  while(tmp->left!=NULL)
  {
    cout << tmp->data << " "; tmp=tmp->left;
  }
  return 0;
}
