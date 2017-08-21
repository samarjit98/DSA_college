#include <iostream>
#include <vector>
using namespace std;

struct listNode
{
  int data;
  listNode* next1;
  listNode* next2;
};

listNode* createNode(int n)
{
  listNode* newNode=new listNode;
  newNode->data=n;
  newNode->next1=NULL;
  newNode->next2=NULL;
  return newNode;
}

void addNode(listNode* &head, int n)
{
  if(head==NULL)head=createNode(n);
  else
  {
    listNode* tmp=head;
    while(tmp!=NULL)
    {
      cout << tmp->data << endl;
      int tag=0;
      cout << "Enter direction:(0 for up/1 for down):-"; cin >> tag;
      if(tag==0)
      {
        if(tmp->next1==NULL)
        {
          tmp->next1=createNode(n);
          break;
        }
        else
        {
          tmp=tmp->next1;
        }
      }
      else
      {
        if(tmp->next2==NULL)
        {
          tmp->next2=createNode(n);
          break;
        }
        else
        {
          tmp=tmp->next2;
        }
      }
    }
    listNode* rear=createNode(n);

    /*listNode* tmp=head; listNode* rear=createNode(n);
    while(tmp->next1!=NULL)
    {
      tmp=tmp->next1;
    }
    tmp->next=rear;*/
  }
}
/*
void printList(listNode* head, listNode* last)
{
  listNode* tmp=head;
  while(tmp!=last)
  {
    cout << tmp->data << " ";
  }
  cout << tmp->data;
}
*/
void printPaths(listNode* head, vector<int> a)
{

  if(head==NULL)return;
  else
  {
    cout << head->data << " "; a.push_back(head->data);
    if(head->next1!=NULL && head->next2!=NULL)
    {
      printPaths(head->next1, a);
      cout << endl;
      //printList(prev, head);
      for(int i=0; i<a.size(); i++)cout << a[i] << " ";
      printPaths(head->next2, a);
      cout << endl;
    }
    else
    {
      printPaths(head->next1, a);
    }
  }
}

int main()
{
  listNode* head=NULL;
  int n;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter node data for list 1:"; cin >> n;
    addNode(head, n);
    cout << "Enter more:"; cin >> ans;
  }
  vector<int> a;
  printPaths(head, a);
}
