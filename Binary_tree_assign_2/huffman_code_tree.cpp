#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct btnode
{
  btnode* left;
  char data;
  int freq;
  btnode* right;
};

struct data_freq
{
  char data;
  int freq;
};

typedef btnode* btptr;

btptr createBTNode(char n, int f)
{
  btptr newNode=new btnode;
  newNode->data=n; newNode->freq=f; newNode->left=NULL; newNode->right=NULL;
  return newNode;
}

bool cmp(btptr a, btptr b)
{
  return a->freq<b->freq;
}

void make_tree(btptr &root, vector<btptr> a)
{
  sort(a.begin(), a.end(), cmp);
  vector<btptr>::iterator it1;
  vector<btptr>::iterator it2;

  while(a.size()!=1)
  {
    it1=a.begin();
    a.erase(a.begin());
    it2=a.begin();
    a.erase(a.begin());

    btptr tmp=createBTNode('#', (*it1)->freq + (*it2)->freq);
    tmp->left=*it1;
    tmp->right=*it2;
    a.push_back(tmp);
    sort(a.begin(), a.end(), cmp);
  }
  root=a[0];
}

void print_tree(btptr root, vector<int> a)
{
  if(root->left==NULL && root->right==NULL)
  {
    cout << root->data << " ";
    for(int i=0; i<a.size(); i++)cout << a[i];
    cout << endl;
    return;
  }
  else
  {
    a.push_back(0);
    print_tree(root->left, a);
    a[a.size()-1]=1;
    print_tree(root->right, a);
  }
}

int main()
{
  btptr root=NULL;
  int n, fr;
  char tmp;
  vector<btptr> a;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; cin >> fr; a.push_back(createBTNode(tmp, fr));
  }
  make_tree(root, a);
  vector<int> b;
  print_tree(root, b);
  return 0;
}
