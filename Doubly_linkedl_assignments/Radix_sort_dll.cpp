#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int data;
  node* next;
};

node* createNode(int n)
{
  node* newNode=new node;
  newNode->data=n;
  newNode->next=NULL;

  return newNode;
}

void addNode(node* &head, int n)
{
  if(head==NULL)
  {
    head=createNode(n); return;
  }

  node* tmp=head;
  while(tmp->next!=NULL)tmp=tmp->next;

  tmp->next=createNode(n);
}

struct dllNode
{
  dllNode* left;
  int digit;
  node* elements;
  dllNode* right;
};

dllNode* createdllNode(int n)
{
  dllNode* newNode=new dllNode;
  newNode->left=NULL; newNode->right=NULL;
  newNode->digit=n; newNode->elements=NULL;

  return newNode;
}

void adddllNode(dllNode* &head, int n)
{
  if(head==NULL)
  {
    head=createdllNode(n); return;
  }

  dllNode* tmp=head;
  while(tmp->right!=NULL)
  {
    tmp=tmp->right;
  }
  tmp->right=createdllNode(n);
  tmp->right->left=tmp;
}

int finMax(vector<int> a)
{
  int max=a[0];
  for(int i=0; i<a.size(); i++)
  {
    if(a[i]>max)max=a[i];
  }
  return max;
}

void createRadix(dllNode* &head)
{
  for(int i=0; i<10; i++)
  {
    adddllNode(head, i);
  }
}

void RadixSort(vector<int> &a)
{
  dllNode* buckets=NULL;
  createRadix(buckets);

  int max=finMax(a);

  for (int exp = 1; max/exp > 0; exp *= 10)
  {
    dllNode* init=buckets;
    while(init!=NULL)
    {
      init->elements=NULL;
      init=init->right;
    }

    for(int i=0; i<a.size(); i++)
    {
      int tmp=a[i];
      tmp=(tmp/exp)%10;
      dllNode* crawler=buckets;
      while(crawler->digit!=tmp)crawler=crawler->right;
      addNode(crawler->elements, a[i]);
    }
    a.clear();
    dllNode* right_crawler=buckets; node* up_crawler=NULL;
    while(right_crawler->right!=NULL)
    {
      up_crawler=right_crawler->elements;
      while(up_crawler!=NULL)
      {
        a.push_back(up_crawler->data);
        up_crawler=up_crawler->next;
      }
      right_crawler=right_crawler->right;
    }
  }
}

int main()
{
  vector<int> v;
  cout << "Enter elements:\n";
  int n, tmp; cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; v.push_back(tmp);
  }
  cout << endl;
  RadixSort(v);
  for(int i=0; i<v.size(); i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}
