#include <iostream>
using namespace std;

struct listNode
{
  int data;
  listNode* next;
};

class Queue
{
  listNode *front, *rear;

public:
  Queue()
  {
    front=NULL; rear=NULL;
  }
  bool isEmpty()
  {
    if(front==NULL)return true;
    return false;
  }
  void enQueue(int x)
  {
    listNode* newNode=new listNode;
    newNode->data=x;
    newNode->next=NULL;
    if(front==NULL)
    {
      front=newNode;
      rear=newNode;
    }
    else
    {
      rear->next=newNode;
      rear=newNode;
    }

  }
  int peek()
  {
    if(!this->isEmpty())return front->data;
    else return -1;
  }
  int deQueue()
  {
    if(!this->isEmpty())
    {
      listNode* tmp=front;
      front=front->next;
      int t=tmp->data;
      delete tmp;
      return t;
    }
  }
};

int main() {
  Queue q;
  for(int i=0; i<=20; i++)q.enQueue(i);
  for(int i=0; i<5; i++)q.deQueue();

  while(!q.isEmpty())
  {
    cout << q.deQueue() << " ";
  }
  return 0;
}
