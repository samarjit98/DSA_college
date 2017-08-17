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

void insertIntoSorted(listNode* &head, listNode* node);

/*void insertionSort(listNode* &head)
{
  listNode* s=NULL;

  listNode* curr=head;
  while(curr!=NULL)
  {
    listNode* nextNode=curr->next;

    insertIntoSorted(s, curr);
    curr=nextNode;
  }

  head=s;
}
*/
void insertionSort(listNode* &head, listNode* curr)
{
  static listNode* s=head;

  if(curr==NULL)
  {
    head=s;
    return;
  }
  else
  {
    listNode* nextNode=curr->next;
    insertIntoSorted(s, curr);
    insertionSort(s, nextNode);
  }
}

void insertIntoSorted(listNode* &head, listNode* node)
{
  if(head==NULL || head->data >= node->data)
  {
    node->next=head;
    head=node;
  }
  else
  {
    listNode* curr=head;
    while(curr->next!=NULL && curr->next->data<node->data)
    {
      curr=curr->next;
    }
    node->next=curr->next; curr->next=node;
  }
}

int main()
{
  listNode* head=NULL;
  int n;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter node data for list :"; cin >> n;
    addNode(head, n);
    cout << "Enter more:"; cin >> ans;
  }
  listNode* tmp=head;
  while(tmp!=NULL)
  {
    cout << tmp->data << " "; tmp=tmp->next;
  }
  cout << endl;
  insertionSort(head, head);
  tmp=head;
  while(tmp!=NULL)
  {
    cout << tmp->data << " "; tmp=tmp->next;
  }

  return 0;
}
