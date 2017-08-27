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

void postorder_ite(btptr root)
{
  if(root==NULL)return;
  else
  {
    stack<btptr> s1;
    s1.push(root);
    root=root->left;
    int sw=0;
    while(!s1.empty() || sw==1)
    {
      if(root==NULL)
      {
        btptr tmp=s1.top(); s1.pop();
        if(tmp->right==NULL)
        {
          cout << tmp->data << " ";
        }
        else
        {
          root=tmp->right; tmp->right=NULL; s1.push(tmp); sw=1;
        }
      }
      else
      {
        s1.push(root);
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
  postorder_ite(root);
  return 0;
}
