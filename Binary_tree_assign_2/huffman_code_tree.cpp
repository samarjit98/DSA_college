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
  return a->freq>b->freq;
}

void make_tree1(btptr &root, vector<btptr> a)
{
  sort(a.begin(), a.end(), cmp);

  while(a.size()!=1)
  {
    btptr &it1=a[a.size()-1];
    a.pop_back();
    btptr &it2=a[a.size()-1];
    a.pop_back();

    btptr tmp=createBTNode('#', it1->freq + it2->freq);
    tmp->left=it1;
    tmp->right=it2;
    a.push_back(tmp);
    sort(a.begin(), a.end(), cmp);
  }
  root=a[0];
}

void make_tree2(btptr &root, vector<btptr> a)
{
  sort(a.begin(), a.end(), cmp);

  while(a.size()!=1)
  {
    btptr &it1=a[a.size()-1];
    a.pop_back();
    btptr &it2=a[a.size()-1];
    a.pop_back();

    btptr tmp=createBTNode('#', it1->freq + it2->freq);
    tmp->right=it1;
    tmp->left=it2;
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
    a.pop_back();
    a.push_back(1);
    print_tree(root->right, a);
  }
}

int main()
{
  btptr root1=NULL;
  btptr root2=NULL;
  int n, fr;
  char tmp;
  vector<btptr> a;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; cin >> fr; a.push_back(createBTNode(tmp, fr));
  }
  make_tree1(root1, a);
  make_tree2(root2, a);
  vector<int> b;
  print_tree(root1, b);
  b.clear();
  cout << endl;
  cout << "OR" << endl;
  print_tree(root2, b);
  return 0;
}
