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

void MergedList(listNode* head1, listNode* head2, listNode* &head)
{
  while(head1!=NULL || head2!=NULL)
  {
    if(head1==NULL)
    {
      while(head2!=NULL)
      {
        addNode(head, head2->data); head2=head2->next;
      }
    }
    else if(head2==NULL)
    {
      while(head1!=NULL)
      {
        addNode(head, head1->data); head1=head1->next;
      }
    }
    else if(head1->data<head2->data)
    {
      addNode(head, head1->data); head1=head1->next;
    }
    else
    {
      addNode(head, head2->data); head2=head2->next;
    }
  }
}

int main()
{
  listNode* head1=NULL; listNode* head2=NULL;
  int n;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter node data for list 1:"; cin >> n;
    addNode(head1, n);
    cout << "Enter more:"; cin >> ans;
  }
  ans='y';
  while(ans=='y')
  {
    cout << "Enter node data for list 2:"; cin >> n;
    addNode(head2, n);
    cout << "Enter more:"; cin >> ans;
  }
  listNode* mergedHead=NULL;
  MergedList(head1, head2, mergedHead);
  listNode* tmp=mergedHead;
  cout << "MERGED LIST: " << endl;
  while(tmp!=NULL)
  {
    cout << tmp->data << " "; tmp=tmp->next;
  }
  return 0;
}
