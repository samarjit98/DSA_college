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
/*
void create_init_tree(btptr &root)
{
    cout << "Enter data:"; int n; cin >> n;
    root=createBTNode(n);
    cout << "Does " << n << " have a left child:"; char ans; cin >> ans;
    if(ans=='y')create_init_tree(root->left);
    cout << "Does " << n << " have a right child:"; cin >> ans;
    if(ans=='y')create_init_tree(root->right);
}
*/
void preorder(btptr root)
{
  if(root!=NULL)
  {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
/*
void create_tree_using_string(btptr &root, string s, int i)
{
  if(i>=s.size())return;

  root=createBTNode(s[i]);
  i++;
  if(s[i]!='.' && s[i+1]=='.')create_tree_using_string(root->left, s, i);
  else if(s[i]=='.' && s[i+1]!='.')create_tree_using_string(root->right, s, i+1);
  else if(s[i]!='.' && s[i+1]!='.')
  {
    create_tree_using_string(root->left, s, i); create_tree_using_string(root->right, s, i+1);
  }
}
*/
void create_tree_using_string(btptr &root, string s)
{
  static int i=0;
  if(i>=s.size())return;
  root=createBTNode(s[i]);
  i++;
  if(s[i]!='.'){ create_tree_using_string(root->left, s);}
  if(s[i]=='.'){ i++;}
  if(s[i]!='.'){ create_tree_using_string(root->right, s);}
  /*
  int j=i+1, vars=0, dots=0;
  while(vars-1!=dots && j<s.size())
  {
    if(s[i]!='.')
    {
      vars++; j++;
    }
    else if(s[i]=='.' && s[i-1]!='.' && j>i+1)
    {
      dots++; j++;
    }
  }
  if(j<s.size() && s[j]!='.')create_tree_using_string(root->right, s, j);
  */
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
