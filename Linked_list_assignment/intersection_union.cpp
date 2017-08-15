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
/*
void printListUnion(listNode* head1, listNode* head2)
{
  listNode* tmp1=head1, tmp2=head2, newListhead=NULL;
  while(tmp1!=NULL && tmp2!=NULL)
  {
    if(tmp1->data==tmp2->data)
    {
      addNode(newListhead, tmp1->data);
    }
    else
    {
      addNode(newListhead, tmp1->data);
      addNode(newListhead, tmp2->data);
    }
    tmp1=tmp1->next;
    tmp2->tmp2->next;
  }
  if(tmp1!=NULL)
  {
    while(tmp1!=NULL)
    {
      listNode* tmp=newListhead; int flag=0;
      while(tmp!=NULL)
      {
        if(tmp->data==tmp1->data)
        {
          flag=1; break;
        }
      }
      if(flag==0)addNode(newListhead, tmp1->data);

      tmp1=tmp1->next;
    }
  }
  else
  {
    while(tmp2!=NULL)
    {
      listNode* tmp=newListhead; int flag=0;
      while(tmp!=NULL)
      {
        if(tmp->data==tmp2->data)
        {
          flag=1; break;
        }
      }
      if(flag==0)addNode(newListhead, tmp2->data);

      tmp2=tmp2->next;
    }
  }

  listNode* tmp=newListhead;
  cout << "LIST UNION" << endl;
  while(tmp!=NULL)
  {
    cout << tmp->data << " ";
    tmp=tmp->next;
  }
}
*/
void printListIntersection(listNode* head1, listNode* head2)
{
  listNode* tmp1=head1; listNode* tmp2=head2; listNode* newListhead=NULL;
  while(tmp1!=NULL)
  {
    while(tmp2!=NULL)
    {
      if(tmp2->data==tmp1->data)addNode(newListhead, tmp2->data);
    }
    tmp2=head2;
  }

  listNode* tmp=newListhead;
  cout << "LIST INTERSECTION:" << endl;
  while(tmp!=NULL)
  {
    cout << tmp->data << " ";
    tmp=tmp->next;
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
//  printListUnion(head1, head2);
  printListIntersection(head1, head2);
  return 0;
}
