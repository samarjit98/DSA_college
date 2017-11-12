#include <iostream>
#include <unordered_map>
using namespace std;

// C++ 11 or above required

struct trie{
  bool leaf;
  unordered_map<char, trie*> alpha;
};
typedef trie* tptr;

tptr newNode()
{
  tptr node=new trie;
  node->leaf=false;

  return node;
}

void insert(tptr *head, char* str)
{
  if(*head==NULL)*head=newNode();

  tptr curr=*head;
  while(*str){
    if(curr->alpha.find(*str)==curr->alpha.end()){
      curr->alpha[*str]=newNode();
    }
    curr=curr->alpha[*str];
    str++;
  }
  curr->leaf=true;
}

bool search(tptr curr, char* str)
{
  if(curr==NULL)return false;
  while(*str){
    if(curr->alpha.find(*str)==curr->alpha.end()){
      return false;
    }
    curr=curr->alpha[*str]; str++;
  }
  return curr->leaf;
}

bool children(tptr curr)
{
  for(auto it: curr->alpha)if(it.second!=NULL)return true;
  return false;
}

bool deletion(tptr &curr, char* str)
{
  if(curr==NULL)return false;

  if(*str){
    if(curr->alpha.find(*str)!=curr->alpha.end() && deletion(curr->alpha[*str], str+1) && !curr->leaf){
      if(!children(curr)){
        delete curr; curr=NULL;
        return true;
      }
      else{
        return false;
      }
    }
  }
  if(*str=='\0' && curr->leaf){
    if(!children(curr)){
      delete curr; curr=NULL;
      return true;
    }
    else{
      curr->leaf=false;
      return false;
    }
  }
}

int main()
{
  tptr head=NULL;
  insert(&head, "foobar");
  insert(&head, "codeorigins");
  insert(&head, "code");
  if(search(head, "foobar"))cout << "foobar" << endl;
  if(search(head, "codeorigins"))cout << "codeorigins" << endl;
  if(search(head, "code"))cout << "code" << endl;
  deletion(head, "code");
  if(search(head, "foobar"))cout << "foobar" << endl;
  if(search(head, "codeorigins"))cout << "codeorigins" << endl;
  if(search(head, "code"))cout << "code" << endl;
  return 0;
}
