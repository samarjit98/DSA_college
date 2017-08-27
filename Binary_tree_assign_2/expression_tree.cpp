#include <bits/stdc++.h>
using namespace std;

union element
{
  int data;
  char oper;
};

struct btnode
{
  int tag;
  element e;
  btnode* left;
  btnode* right;
};

typedef btnode* btptr;

btptr createBTNode(int tag, element n)
{
  btptr newNode=new btnode;
  if(tag==0)
  {
    newNode->tag=0;
    newNode->e.data=n.data;
    newNode->left=NULL; newNode->right=NULL;

    return newNode;
  }
  else
  {
    newNode->tag=1;
    newNode->e.oper=n.oper;
    newNode->left=NULL; newNode->right=NULL;

    return newNode;
  }
}

bool isOperator(char ch)
{
  return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

void create_tree(btptr &root, string a)
{
  stack<btptr> s;
  string sub;
  for(int i=0; i<a.size(); i++)
  {
    if(isOperator(a[i]))
    {
      btptr &tmp1=s.top(); s.pop();
      btptr &tmp2=s.top(); s.pop();
      element n; n.oper=a[i];
      btptr tmp=createBTNode(1, n);
      tmp->left=tmp2; tmp->right=tmp1;
      s.push(tmp);
    }
    else if(a[i]=' ')
    {
      if(!sub.empty())
      {
        int t=atoi(sub.c_str()); sub.clear();
        element n; n.data=t;
        btptr tmp=createBTNode(0, n);
        s.push(tmp);
      }
    }
    else
    {
      sub.push_back(a[i]);
    }
  }

  if(s.size()==1)root=s.top();
  else cout << "NOT POSSIBLE!";
}

int oper(int a, int b, char c)
{
  if(c=='+')return a+b;
  else if(c=='*')return a*b;
  else if(c=='-')return a-b;
  else if(c=='/')return a/b;
}

int eval(btptr root)
{
  if(root->tag==0)return (root->e).data;
  else
  {
    return oper(eval(root->left), eval(root->right), (root->e).oper);
  }
}

int main()
{
  string s;
  getline(cin , s);
  btptr root=NULL;
  create_tree(root, s);
  cout << eval(root) << endl;
  return 0;
}
