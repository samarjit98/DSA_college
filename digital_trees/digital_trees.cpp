#include <iostream>
#include <string>
using namespace std;

struct dtnode
{
  string data;
  dtnode* left;
  dtnode* right;
};

typedef dtnode* dtptr;

dtptr createNode(string n)
{
  dtptr nn=new dtnode;
  nn->data=n;
  nn->left=NULL;
  nn->right=NULL;
  return nn;
}

void createTree(dtptr &T, string n, int i=0)
{
  if(T==NULL)T=createNode(n);
  else
  {
    if(n[i]=='0')
    {
      createTree(T->left, n, i+1);
    }
    else
    {
      createTree(T->right, n, i+1);
    }
  }
}

bool search(dtptr T, string n, int j=0)
{
  if(T==NULL)return false;
  else
  {
    //static int j=0;
    for(int i=j; i<n.size(); i++)
    {
      if(n[i]!=T->data[i])
      {
        if(n[j]=='0')return search(T->left, n, j+1);
        else return search(T->right, n, j+1);
      }
    }
    return true;
  }
}

void printTree(dtptr root)
{
  if(root==NULL)return;
  else
  {
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
  }
}

int main()
{
  dtptr root=NULL;
  char ans='y';
  while(ans=='y')
  {
    string s;
    cout << "Enter data:-"; cin >> s;
    createTree(root, s);
    cin >> ans;
  }
  printTree(root);
  cout << endl;
  cout << "Enter search item:-";
  string s;
  cin >> s;
  if(search(root,s))cout << "YES";
  else cout << "NO";
  return 0;
}
