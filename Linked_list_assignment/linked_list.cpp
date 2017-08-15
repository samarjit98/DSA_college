#include <iostream>
using namespace std;

struct lptr{
  int data;
  lptr *next;
};

lptr* createNode(int x)
{
  lptr* newNode=new lptr;
  newNode->data=x;
  newNode->next=NULL;
}

void addNode(lptr* head, int x)
{
  lptr* newNode=createNode(x);

  lptr* tmp=head;

  while(tmp->next!=NULL)
  {
    tmp=tmp->next;
  }
  tmp->next=newNode;
}

void printLL(lptr* head)
{
  lptr* tmp=head;
  while(tmp!=NULL)
  {
    cout << tmp->data << " ";
    tmp=tmp->next;
  }
}

int main()
{
  lptr* head=createNode(1);

  for(int i=2; i<=20; i++)
  {
    addNode(head, i);
  }
  printLL(head);
  return 0;
}
