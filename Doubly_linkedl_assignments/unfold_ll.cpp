#include <iostream>
using namespace std;

struct listNode
{
  int data;
  listNode* next;
};

listNode* createNode(int n)
{
  listNode* newNode=new listNode;
  newNode->data=n;
  newNode->next=NULL;
  return newNode;
}

void addNode(listNode* &head, int n)
{
  if(head==NULL)head=createNode(n);
  else
  {
    listNode* tmp=head; listNode* rear=createNode(n);
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
    }
    tmp->next=rear;
  }
}

void printList(listNode* head)
{
  if(head==NULL)return;

  cout << head->data << " ";
  printList(head->next);
}

void separate(listNode* &list1, listNode* &list2)
{
  int l1=0, l2=0, diff=0;
  listNode* tmp1=list1; listNode* tmp2=list2;
  while(tmp1!=NULL)
  {
    l1++; tmp1=tmp1->next;
  }
  while(tmp2!=NULL)
  {
    l2++; tmp2=tmp2->next;
  }
  if(l1<l2)
  {
    tmp1=list2; tmp2=list1; diff=l2-l1;
  }
  else
  {
    tmp2=list2; tmp1=list1; diff=l1-l2;
  }
  for(int i=0; i<diff; i++)tmp1=tmp1->next;
  while(tmp1!=NULL && tmp2!=NULL)
  {
    if(tmp1->next==tmp2->next)break;
    else
    {
      tmp1=tmp1->next; tmp2=tmp2->next;
    }
  }

  listNode* newList=NULL;
  listNode* tmp=tmp1;
  tmp=tmp->next;
  while(tmp!=NULL)
  {
    addNode(newList, tmp->data);
  }

  while(newList!=NULL)
  {
    tmp1->next=createNode(newList->data); tmp2->next=createNode(newList->data);
    tmp1=tmp1->next; tmp2=tmp2->next;
    newList=newList->next;
  }


}

int main()
{
  listNode *l1=NULL, *l2=NULL;
  addNode(l1, 5);
  addNode(l2, 3);
  addNode(l1, 8);
  addNode(l2, 6);
  addNode(l2, 1);

  listNode* inter=createNode(4);
  listNode* tmp=l1;

  while(tmp->next!=NULL)tmp=tmp->next;
  tmp->next=inter;

  tmp=l2;

  while(tmp->next!=NULL)tmp=tmp->next;
  tmp->next=inter;

  addNode(l1, 9);

  printList(l1);
  cout << endl;
  printList(l2);
  cout << endl;

  cout << "After separating:" << endl;
  printList(l1);
  cout << endl;
  printList(l2);
  cout << endl;

  return 0;
}
