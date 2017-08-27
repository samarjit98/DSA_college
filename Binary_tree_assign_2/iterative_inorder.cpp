#include <iostream>
#include <vector>
#include <stack>
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

vector<int> preorder;
void create_tree(btptr &root, vector<int> inorder)
{
  if(inorder.empty())return;
  else
  {
    int tmp=preorder[0];
    root=createBTNode(preorder[0]);
    preorder.erase(preorder.begin());
    int i=0;
    vector<int> a;
    while(inorder[i]!=tmp && i<inorder.size())
    {
      a.push_back(inorder[i]); i++;
    }
    create_tree(root->left, a);

    a.clear();

    i++;
    while(i<inorder.size())
    {
      a.push_back(inorder[i]); i++;
    }
    create_tree(root->right, a);
  }
}

void inorder_ite(btptr root)
{
  if(root==NULL)return;
  else
  {
    stack<btptr> s;
    s.push(root);
    root=root->left;
    int sw=0;
    while(!s.empty() || sw==1)
    {
      if(root==NULL)
      {
        btptr tmp=s.top(); s.pop();
        cout << tmp->data << " ";
        if(tmp->right!=NULL){ root=tmp->right; sw=1; }
      }
      else
      {
        s.push(root);
        root=root->left;
        if(sw==1)sw=0;
      }
    }
  }
}

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> inorder;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; preorder.push_back(tmp);
  }
  for(int i=0; i<n; i++)
  {
    cin >> tmp; inorder.push_back(tmp);
  }
  btptr root=NULL;
  create_tree(root, inorder);
  inorder_ite(root);
  return 0;
}
