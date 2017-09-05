#include <iostream>
#include <vector>
using namespace std;

const int k=4;

struct kdnode
{
  vector<int> data;
  kdnode* left;
  kdnode* right;
};

typedef kdnode* kdptr;

kdptr createNode(vector<int> n)
{
  kdptr newNode=new kdnode;
  for(int i=0; i<n.size(); i++)
  {
    newNode->data.push_back(n[i]);
  }
  newNode->left=NULL;
  newNode->right=NULL;

  return newNode;
}

void addNode(kdptr &T, vector<int> n)
{
  if(T==NULL)T=createNode(n);
  else
  {
    static int i=0;
    if(T->data[i]<n[i])
    {
      i++;
      if(i>=k)i=0;
      addNode(T->right, n);
    }
    else
    {
      i++;
      if(i>=k)i=0;
      addNode(T->left, n);
    }
  }
}

bool search(kdptr T, vector<int> n)
{
  if(T==NULL)return false;
  else
  {
    static int i=0;
    if(T->data==n)return true;
    else
    {
      if(T->data[i]<n[i])
      {
        i++;
        if(i>=k)i=0;
        return search(T->right, n);
      }
      else
      {
        i++;
        if(i>=k)i=0;
        return search(T->left, n);
      }
    }
  }
}

void printTree(kdptr T)
{
  if(T==NULL)return;
  else
  {
    for(int i=0; i<k; i++)cout << T->data[i]<< " ";
    cout << "||";
    printTree(T->left);
    printTree(T->right);
  }
}

int main()
{
  kdptr T=NULL;
  char ans='y';
  while(ans=='y')
  {
    cout << "Enter data:";
    vector<int> a;
    int tmp;
    for(int i=0; i<k; i++)
    {
      cin >> tmp; a.push_back(tmp);
    }
    addNode(T, a);
    cin >> ans;
  }
  printTree(T);
  cout << endl;
  cout << "Enter search array:";
  vector<int> c;
  int t;
  for(int i=0; i<k; i++)
  {
    cin >> t; c.push_back(t);
  }
  if(search(T, c))cout << "YES";
  else cout << "NO";
  return 0;
}
