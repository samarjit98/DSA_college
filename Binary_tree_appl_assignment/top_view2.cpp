#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct btnode
{
  btnode* left;
  int data;
  btnode* right;
};

struct node_vec
{
  int level;
  int data;
};

typedef btnode* btptr;

btptr createBTNode(int n)
{
  btptr newNode=new btnode;
  newNode->data=n; newNode->left=NULL; newNode->right=NULL;
  return newNode;
}

void create_init_tree(btptr &root)
{
    cout << "Enter data:"; int n; cin >> n;
    root=createBTNode(n);
    cout << "Does " << n << " have a left child:"; char ans; cin >> ans;
    if(ans=='y')create_init_tree(root->left);
    cout << "Does " << n << " have a right child:"; cin >> ans;
    if(ans=='y')create_init_tree(root->right);
}

vector<node_vec> a;
void printTopLeft(btptr root, int level=0)
{
  if(root==NULL)return;
  node_vec curr;
  curr.data=root->data; curr.level=level; int flag=0;
  for(int i=0; i<a.size(); i++)
  {
    if(a[i].level==level){ flag=1; break;}
  }
  if(flag==0)a.push_back(curr);

  printTopLeft(root->left, level-1);
  printTopLeft(root->right, level+1);
}

bool cmp(const node_vec a, const node_vec b)
{
  return a.level<b.level;
}

void printTopView(btptr root)
{
  printTopLeft(root);

  sort(a.begin(), a.end(), cmp);

  for(int i=0; i<a.size(); i++)cout << a[i].data << " ";
  cout << endl;
}

int main()
{
  btptr head=NULL;
  create_init_tree(head);
  cout << endl;
  printTopView(head);
  return 0;
}
