#include <iostream>
#include <fstream>
using namespace std;

struct Key{
  int val;
  int pos;
};

class BTreeNode{
  int t;
  int n;
  Key *keys;
  bool leaf;
  BTreeNode* *child;

public:

  friend class BTree;
  BTreeNode(int _t, bool _leaf);
  void insertNonFull(Key k);
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
  Key getStruct(int k);
  void insert(int k);
  void printTree();
};

BTreeNode::BTreeNode(int _t, bool _leaf)
{
  t=_t; leaf=_leaf; n=0;
  keys=new Key[2*t-1];
  child=new BTreeNode*[2*t];
}

void BTreeNode::traverse()
{
  int i=0;
  for(i=0; i<n; i++){
    if(!leaf)child[i]->traverse();
    cout << keys[i].val << " ";
  }
  if(!leaf)child[i]->traverse();
}

Key BTree::getStruct(int k)
{
  ofstream f;
  f.open("BTreeFile.txt", ios::app);
  int pos=f.tellp();
  f << k << " ";
  Key tmp={k, pos};
  return tmp;
}

void BTree::insert(int k)
{
  if(root==NULL){
    Key tmp=getStruct(k);
    root=new BTreeNode(t, true);
    root->keys[0]=tmp;
    root->n=1;
  }
  else{
    Key tmp=getStruct(k);
    if(root->n==2*t-1){
      BTreeNode *s=new BTreeNode(t, false);
      s->child[0]=root;
      s->splitChild(0, root);

      if(tmp.val<s->keys[0].val){
        s->child[0]->insertNonFull(tmp);
      }
      else{
        s->child[1]->insertNonFull(tmp);
      }

      root=s;
    }
    else{
      root->insertNonFull(tmp);
    }
  }
}

void BTreeNode::insertNonFull(Key k)
{
  int i=n-1;
  if(leaf){
    while(i>=0 && keys[i].val>k.val){
      keys[i+1]=keys[i];
      i--;
    }
    keys[i+1]=k;
    n++;
  }
  else{
    while(i>=0 && keys[i].val>k.val){
      i--;
    }

    if(child[i+1]->n==2*t-1){
      splitChild(i+1, child[i+1]);
      if(keys[i+1].val<k.val)i++;
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
  for(int i=0; i<n; i++)cout << keys[i].val << " ";
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
  BTree b(2);
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
