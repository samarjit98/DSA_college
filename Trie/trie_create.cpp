#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
using namespace std;

map<char, int> a;
map<char, int>::iterator it;

struct tnode{
  int f;
  vector<tnode*> alpha;
  string str;
};

typedef tnode* tptr;

tptr createIndexNode()
{
  tptr newNode=new tnode;
  newNode->f=1;
  for(int i=0; i<27; i++)newNode->alpha.push_back(NULL);

  return newNode;
}

tptr createLeafNode(string s)
{
  tptr newNode=new tnode;
  newNode->f=0;
  newNode->str=s;

  return newNode;
}

void create(tptr &T, string s, int i=0, int j=0)
{
  if(j!=0 && T==NULL){
    j--; it=a.find(s[i]); i++;
    T=createIndexNode();
    create(T->alpha[it->second], s, i, j);
  }
  else if(T==NULL && j==0){
    T=createLeafNode(s);
  }
  else if(T->f==1){
    it=a.find(s[i]); i++;
    create(T->alpha[it->second], s, i);
  }
  else if(T->f==0){
    string stor=T->str;
    int l=0;
    for(int i1=i+1; i1<s.size(); i1++){
      if(stor[i1]==s[i1])l++;
      else break;
    }
    T->alpha.clear(); T->f=1;
    for(int i1=0; i1<27; i1++)T->alpha.push_back(NULL);
    T->str.clear();

    it=a.find(s[i]); i++;
    create(T->alpha[it->second], s, i, l);
    i--;
    it=a.find(stor[i]); i++;
    create(T->alpha[it->second], stor, i, l);
  }
}

bool retrieve(tptr T, string s, int i=0)
{
  if(T==NULL)return false;
  else if(T->f==0){
    return (T->str==s);
  }
  else{
    it=a.find(s[i]); i++;
    return retrieve(T->alpha[it->second], s, i);
  }
}

void inorder(tptr T)
{
  if(T==NULL)return;
  else if(T->f==0){
    cout << T->str << " ";
  }
  else{
    for(int i=0; i<T->alpha.size(); i++)inorder(T->alpha[i]);
  }
}

int main()
{
  char l='a';
  a.insert(pair<char, int> (' ', 0));
  for(int i=1; i<=26; i++){
    a.insert(pair<char, int> (l, i)); l++;
  }

  string s;
  tptr T=NULL;

  char ans='y';
  while(ans=='y'){
    cin >> s;
    s.push_back(' ');
    create(T, s);
    cin >> ans;
  }

  cout << endl;
  inorder(T);
  cout << endl << endl;
  ans='y';
  while(ans=='y'){
    cin >> s;
    s.push_back(' ');
    if(retrieve(T, s))cout << "FOUND" << endl;
    else cout << "NOT FOUND" << endl;
    cin >> ans;
  }
  return 0;
}
