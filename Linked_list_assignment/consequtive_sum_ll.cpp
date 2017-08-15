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

void deleteFront(listNode* &head)
{
  if(head==NULL)return;

  listNode* tmp=head;
  head=head->next;
  delete tmp;
}

void ConsequtiveSum(listNode* head, int sum)
{
  int currSum=0;listNode* marker2=NULL;
  listNode* tmp=head;

  while(tmp!=NULL)
  {
    if(currSum<sum)
    {
      currSum+=tmp->data;
    }

    if(currSum==sum)
    {
      marker2=tmp; break;
    }
    else if(currSum>sum)
    {
      currSum=currSum-head->data;
      deleteFront(head);
    }

    if(tmp->next==NULL)
    {
      cout << "DOES NOT EXIST!"; return;
    }

    if(currSum<sum)tmp=tmp->next;
  }

  while(head!=marker2->next)
  {
    cout << head->data << " ";
    head=head->next;
  }
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
  cout << "Enter sum:"; cin >> n;
  ConsequtiveSum(head, n);
  return 0;
}
