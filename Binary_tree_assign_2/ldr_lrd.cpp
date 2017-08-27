#include <iostream>
#include <vector>
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

vector<int> postorder;
void create_tree(btptr &root, vector<int> inorder)
{
  if(inorder.empty())return;
  else
  {
    int tmp=postorder[postorder.size()-1];
    root=createBTNode(tmp);
    postorder.pop_back();
    int i=0;
    vector<int> a;
    while(inorder[i]!=tmp && i<inorder.size())
    {
      i++;
    }
    i++;
    while(i<inorder.size())
    {
      a.push_back(inorder[i]); i++;
    }
    create_tree(root->right, a);

    a.clear();

    i=0;
    while(i<inorder.size() && inorder[i]!=tmp)
    {
      a.push_back(inorder[i]); i++;
    }
    create_tree(root->left, a);
  }
}

void preorder(btptr root)
{
  if(root==NULL)return;
  else
  {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> inorder;
  for(int i=0; i<n; i++)
  {
    cin >> tmp; postorder.push_back(tmp);
  }
  for(int i=0; i<n; i++)
  {
    cin >> tmp; inorder.push_back(tmp);
  }
  btptr root=NULL;
  create_tree(root, inorder);
  preorder(root);
  return 0;
}
