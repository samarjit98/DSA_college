#include <iostream>
using namespace std;

struct btnode
{
  btnode* left;
  char data;
  btnode* right;
};

typedef btnode* btptr;

btptr createBTNode(char n)
{
  btptr newNode=new btnode;
  newNode->data=n; newNode->left=NULL; newNode->right=NULL;
  return newNode;
}

void preorder(btptr root)
{
  if(root!=NULL)
  {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void create_tree_using_string(btptr &root, string s)
{
  static int i=0;
  if(i>=s.size())return;
  root=createBTNode(s[i]);
  i++;
  if(s[i]!='.'){ create_tree_using_string(root->left, s);}
  if(s[i]=='.'){ i++;}
  if(s[i]!='.'){ create_tree_using_string(root->right, s);}
}

int main()
{
  string s;
  cin >> s;
  btptr root=NULL;
  create_tree_using_string(root, s);
  preorder(root);
  return 0;
}
