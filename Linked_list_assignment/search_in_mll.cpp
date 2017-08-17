#include <iostream>
using namespace std;

struct node
{
  int tag;
  union u
  {
    int n;
    node* link;
  } data;
  node* next;
};

node* create(node* &curr)
{
  int d;
  cout << "Enter elements:-"; cin >> d;
  while(d--)
  {
    if(curr==NULL)
    {
      curr=new node; curr->next=NULL;
      cout << "Enter tag:-"; cin >> curr->tag;
      if(curr->tag==0)
      {
        cout << "Enter data:-"; cin >> (curr->data).n;
      }
      else
      {
        (curr->data).link=NULL; cout << "New set creation:" << endl; create((curr->data).link); cout << "A set ends here!";
      }
    }
    else
    {
      node* tmp=curr;
      while(tmp->next!=NULL)
        tmp=tmp->next;
      tmp->next=new node;
      tmp=tmp->next;
      tmp->next=NULL;
      cout << "Enter tag:-"; cin >> tmp->tag;
      if(tmp->tag==0)
      {
        cout << "Enter data:-"; cin >> (tmp->data).n;
      }
      else
      {
        (tmp->data).link=NULL; cout << "New set creation:" << endl; create((tmp->data).link); cout << "A set ends here!" << endl;
      }
    }
  }
}

void printList(node* curr)
{
  if(curr==NULL)
  {
    cout << "), "; return;
  }
  else if(curr->tag==0)
  {
    if(curr->next!=NULL)cout << (curr->data).n << ", ";
    else cout << (curr->data).n;
    printList(curr->next);
  }
  else
  {
    cout << "( ";
    printList((curr->data).link); printList(curr->next);
  }
}

bool searchMLL(node* curr, int num)
{
  int flag=0;
  while(curr!=NULL)
  {
    if(curr->tag==1)
    {
      if(searchMLL((curr->data).link, num))
      {
        flag=1; break;
      }
    }
    else if((curr->data).n==num)
    {
      flag=1; break;
    }

    if(flag==1)break;

    curr=curr->next;
  }

  if(flag==0)return false;
  else return true;
}

int main()
{
  node* head=NULL;
  create(head);
  cout << "( "; printList(head); cout << endl;
  cout << "Enter element to search:";
  int n; cin >> n;
  if(searchMLL(head, n))cout << "FOUND!";
  else cout << "NOT FOUND!";
  return 0;
}
