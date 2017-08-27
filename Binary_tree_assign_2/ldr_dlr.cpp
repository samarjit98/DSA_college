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

void postorder(btptr root)
{
  if(root==NULL)return;
  else
  {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
  postorder(root);
  return 0;
}
