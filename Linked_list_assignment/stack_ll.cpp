#include <iostream>
using namespace std;

struct listNode
{
  int data;
  listNode* next;
};

class Stack
{
  listNode* head;

public:
  Stack()
  {
    head=NULL;
  }
  bool isEmpty()
  {
    if(head==NULL)return true;
    return false;
  }
  void push(int x)
  {
    listNode* newNode=new listNode;
    newNode->data=x;
    newNode->next=head;
    head=newNode;
  }
  int top()
  {
    if(!this->isEmpty())return head->data;
    else return -1;
  }
  int pop()
  {
    if(!this->isEmpty())
    {
      listNode* tmp=head;
      head=head->next;
      int t=tmp->data;
      delete tmp;
      return t;
    }
  }
};

int main() {
  Stack s;
  for(int i=0; i<=20; i++)s.push(i);
  for(int i=0; i<5; i++)s.pop();

  while(!s.isEmpty())
  {
    cout << s.pop() << " ";
  }
  return 0;
}
