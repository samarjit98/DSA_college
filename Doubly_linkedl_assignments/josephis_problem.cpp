#include <iostream>
#include <vector>
using namespace std;

struct dllNode
{
  dllNode* left;
  int data;
  dllNode* right;
};

dllNode* createNode(int n)
{
  dllNode* newNode=new dllNode;
  newNode->left=NULL; newNode->right=NULL;
  newNode->data=n;

  return newNode;
}

void addNode(dllNode* &head, int n)
{
  if(head==NULL)
  {
    head=createNode(n); return;
  }

  dllNode* tmp=head;
  while(tmp->right!=NULL)
  {
    tmp=tmp->right;
  }
  tmp->right=createNode(n);
  tmp->right->left=tmp;
}

void CreateTheCircle(dllNode* &head, vector<int> arr)
{
  for(int i=0; i<arr.size(); i++)
  {
    addNode(head, arr[i]);
  }

  dllNode* tmp=head;

  while(tmp->right!=NULL)
  {
    tmp=tmp->right;
  }

  tmp->right=head;
  head->left=tmp;
}

void PrintTheCircle(dllNode* head)
{
  int tmp=head->data;
  cout << head->data << " "; head=head->right;
  while(head->data!=tmp)
  {
    cout << head->data << " "; head=head->right;
  }
  cout << endl;
}

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> a;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; a.push_back(tmp);
  }
  dllNode* head=NULL;
  CreateTheCircle(head, a);
  PrintTheCircle(head);
  dllNode* curr=head;
  for(int i=0; i<n-1; i++)
  {
    cout << "Enter a position:-"; cin >> tmp;
    for(int i=0; i<tmp; i++)curr=curr->right;
    dllNode* dead_guy=curr; curr=curr->right;
    dllNode* prev=dead_guy->left;
    prev->right=curr;
    curr->left=prev;
    delete dead_guy;

    PrintTheCircle(curr);
  }
  return 0;
}
