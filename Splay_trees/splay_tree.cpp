#include <iostream>
using namespace std;

struct snode
{
  int data;
  snode* left;
  snode* right;
};

typedef snode* sptr;

sptr createNode(int n)
{
  sptr nn=new snode; nn->left=nn->right=NULL; nn->data=n;
  return nn;
}

void insert(sptr &T, int n)
{
  if(T==NULL)T=createNode(n);
  else if(n>T->data)insert(T->right, n);
  else insert(T->left, n);
}

sptr leftrotate(sptr &T)
{
  sptr Z=T->right;
  sptr T2=T->right->left;
  T->right=T2;
  Z->left=T;
  return Z;
}

sptr rightrotate(sptr &T)
{
  sptr Z=T->left;
  sptr T2=T->left->right;
  T->left=T2;
  Z->right=T;
  return Z;
}

bool search(sptr &T, int k)
{
  if(T==NULL)return false;
  if(T->data==k)return true;
  else if(T->data<k)
  {
    if(T->right!=NULL && search(T->right, k)){T=leftrotate(T); return true;}
    return false;
  }
  else
  {
    if(T->left!=NULL && search(T->left, k)){T=rightrotate(T); return true;}
    return false;
  }
}

void preorder(sptr T)
{
  if(T==NULL)return;
  cout << T->data << " ";
  preorder(T->left);
  preorder(T->right);
}

void inorder(sptr T)
{
  if(T==NULL)return;
  inorder(T->left);
  cout << T->data << " ";
  inorder(T->right);
}

int main()
{
  sptr root=NULL;
  char ans='y';
  while(ans=='y')
  {
    int n;  cin >> n; insert(root, n);
    cin >> ans;
  }
  ans='y';
  while(ans=='y')
  {
    int k; cin >> k;
    if(search(root, k)){cout << "FOUND" << endl; preorder(root); cout << endl; inorder(root);}
    else{cout << "NOT FOUND" << endl; preorder(root); cout << endl; inorder(root);}
    cout << endl;
    cin >> ans;
  }
  return 0;
}
