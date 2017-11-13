#include <iostream>
#include <vector>
using namespace std;

class BTreeNode{
  int t;
  int n;
  int *keys;
  bool leaf;
  BTreeNode* *child;

public:

  friend class BTree;
  BTreeNode(int _t, bool _leaf);
  void insertNonFull(int k);
  void splitChild(int i, BTreeNode* y);
  void traverse();
  void printNode();
};

class BTree{
  BTreeNode* root;
  int t;

public:

  BTree(int _t)
  {
    t=_t; root=NULL;
  }
  void traverse()
  {
    if(root!=NULL){
      root->traverse();
    }
  }
  void insert(int k);
  void printTree();
};

BTreeNode::BTreeNode(int _t, bool _leaf)
{
  t=_t; leaf=_leaf; n=0;
  keys=new int[2*t-1];
  child=new BTreeNode*[2*t];
}

void BTreeNode::traverse()
{
  int i=0;
  for(i=0; i<n; i++){
    if(!leaf)child[i]->traverse();
    cout << keys[i] << " ";
  }
  if(!leaf)child[i]->traverse();
}

void BTree::insert(int k)
{
  if(root==NULL){
    root=new BTreeNode(t, true);
    root->keys[0]=k;
    root->n=1;
  }
  else{
    if(root->n==2*t-1){
      BTreeNode *s=new BTreeNode(t, false);
      s->child[0]=root;
      s->splitChild(0, root);

      if(k<s->keys[0]){
        s->child[0]->insertNonFull(k);
      }
      else{
        s->child[1]->insertNonFull(k);
      }

      root=s;
    }
    else{
      root->insertNonFull(k);
    }
  }
}

void BTreeNode::insertNonFull(int k)
{
  int i=n-1;
  if(leaf){
    while(i>=0 && keys[i]>k){
      keys[i+1]=keys[i];
      i--;
    }
    keys[i+1]=k;
    n++;
  }
  else{
    while(i>=0 && keys[i]>k){
      i--;
    }

    if(child[i+1]->n==2*t-1){
      splitChild(i+1, child[i+1]);
      if(keys[i+1]<k)i++;
    }
    child[i+1]->insertNonFull(k);
  }
}

void BTreeNode::splitChild(int i, BTreeNode* y)
{
  BTreeNode* z=new BTreeNode(t, y->leaf);
  z->n=t-1;

  for(int j=0; j<t-1; j++)z->keys[j]=y->keys[j+t];

  if(!y->leaf){
    for(int j=0; j<t; j++)z->child[j]=y->child[j+t];
  }

  y->n=t-1;

  for(int j=n; j>=i+1; j--)child[j+1]=child[j];
  child[i+1]=z;

  for(int j=n-1; j>=i; j--)keys[j+1]=keys[j];
  keys[i]=y->keys[t-1];
  n++;
}

void BTreeNode::printNode()
{
  cout << "( ";
  for(int i=0; i<n; i++)cout << keys[i] << " ";
  cout << ")" << endl;
  if(!leaf){
    for(int i=0; i<=n; i++)if(child[i]!=NULL)child[i]->printNode();
  }
}

void BTree::printTree()
{
  if(root==NULL){
    cout << "Empty"; return;
  }
  else root->printNode();
}

int main()
{
  BTree b(3);
  char ans='y';
  while(ans=='y'){
    int t;
    cin >> t;
    b.insert(t);
    cin >> ans;
  }
  b.traverse();
  cout << endl;
  b.printTree();
  return 0;
}
