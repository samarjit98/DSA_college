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

int middleValue(listNode* head)
{
  listNode *tmp1=head, *tmp2=head; int s=0, count=1;
  while(tmp1->next!=NULL)
  {
    if(s==0)
    {
      tmp1=tmp1->next; count++; s=1;
    }
    else
    {
      tmp1=tmp1->next;
      tmp2=tmp2->next; count++; s=0;
    }
  }

  return tmp2->data;
}

int main()
{
  listNode* head=NULL;
  int n;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter node data for list:"; cin >> n;
    addNode(head, n);
    cout << "Enter more:"; cin >> ans;
  }
  cout << endl << "Middle element: " << middleValue(head) << endl;
  return 0;
}
