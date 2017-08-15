#include <iostream>
using namespace std;

struct listNode
{
  int coeff;
  int expo;
  listNode* next;
};

listNode* createNode(int n, int m)
{
  listNode* newNode=new listNode;
  newNode->coeff=n;
  newNode->expo=m;
  newNode->next=NULL;
  return newNode;
}

void addNode(listNode* &head, int n, int m)
{
  if(head==NULL)head=createNode(n, m);
  else
  {
    listNode* tmp=head; listNode* rear=createNode(n, m);
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
    }
    tmp->next=rear;
  }
}

void Polynomial_addition(listNode* head1, listNode* head2, listNode* &head)
{
  while(head1!=NULL || head2!=NULL)
  {
    if(head1==NULL)
    {
      while(head2!=NULL)
      {
        addNode(head, head2->coeff, head2->expo); head2=head2->next;
      }
    }
    else if(head2==NULL)
    {
      while(head1!=NULL)
      {
        addNode(head, head1->coeff, head1->expo); head1=head1->next;
      }
    }
    else if(head1->expo>head2->expo)
    {
      addNode(head, head1->coeff, head1->expo); head1=head1->next;
    }
    else if(head1->expo<head2->expo)
    {
      addNode(head, head2->coeff, head2->expo); head2=head2->next;
    }
    else
    {
      addNode(head, head1->coeff + head2->coeff, head1->expo); head1=head1->next; head2=head2->next;
    }
  }
}

int main()
{
  listNode* head1=NULL; listNode* head2=NULL;
  int n, m;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter coeff data for polynomial 1:"; cin >> n;
    cout << "Enter exponent data for polynomial 1:"; cin >> m;
    addNode(head1, n, m);
    cout << "Enter more:"; cin >> ans;
  }
  ans='y';
  while(ans=='y')
  {
    cout << "Enter coeff data for polynomial 2:"; cin >> n;
    cout << "Enter exponent data for polynomial 2:"; cin >> m;
    addNode(head2, n, m);
    cout << "Enter more:"; cin >> ans;
  }
  listNode* mergedHead=NULL;
  Polynomial_addition(head1, head2, mergedHead);
  listNode* tmp=mergedHead;
  cout << "RESULTANT: " << endl;
  while(tmp!=NULL)
  {
    cout << tmp->coeff << "X^" << tmp->expo << " + "; tmp=tmp->next;
  }
  cout << "0";
  return 0;
}
