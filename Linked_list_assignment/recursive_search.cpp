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

bool searchRecursive(listNode* head, int n)
{
  if(head==NULL)return false;
  else if(head->data==n)return true;
  else return searchRecursive(head->next, n);
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
  ans='y';
  while(ans=='y')
  {
    cout << "Enter search value:"; cin >> n;
    if(searchRecursive(head, n))cout << "YES" << endl;
    else cout << "NO" << endl;
    cout << "Enter more:"; cin >> ans;
  }
  return 0;
}
