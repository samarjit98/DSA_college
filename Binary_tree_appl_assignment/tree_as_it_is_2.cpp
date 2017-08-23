#include <iostream>
#include <queue>
using namespace std;

struct btnode
{
  btnode* left;
  int data;
  btnode* right;
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
/*
vector<int> a;
void order_store(btptr root)
{
  if(root==NULL)return;
  else
  {
    order_store(root->left);
    a.push_back(root->data);
    order_store(root->right);
  }
}
*/
/*
void levelorder(btptr root)
{
  if(root==NULL)return;

  btptr spcl=new btnode;
  spcl->data=-1; spcl->left=NULL; spcl->right=NULL;

  queue<btptr> q;
  q.push(root); int j=0, k=0;
  while(!q.empty())
  {
    int i=q.size();

    while(i>0)
    {
      btptr tmp=q.front(); q.pop();
      int sp;
      for(sp=0; sp<a.size(); sp++){if(tmp->data==a[sp])break;}
      while(j<sp){j++; k++; cout << " ";}
      cout << tmp->data;
      if(tmp->left!=NULL)q.push(tmp->left);
      if(tmp->right!=NULL)q.push(tmp->right);
      i--;
    }
    cout << endl; j=0;
  }
}
*/

void printAsItIs(btptr root, int sp=0)
{
  if(root==NULL)return;

  sp+=10;

  printAsItIs(root->right, sp); cout << endl;
  for(int i=10; i<=sp; i++)cout << " "; cout << root->data; cout << endl;
  printAsItIs(root->left, sp);
}

int main()
{
  btptr root=NULL;
  create_init_tree(root);
  cout << endl;
  //order_store(root);
  printAsItIs(root);
  return 0;
}
