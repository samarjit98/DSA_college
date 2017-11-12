#include <stdio.h>
#include <stdlib.h>

struct Trie{
  int leaf;
  struct Trie* alpha[26];
};

typedef struct Trie trie;
typedef struct Trie* tptr;

tptr newNode()
{
  tptr node=(tptr)malloc(sizeof(trie));
  node->leaf=0;
  for(int i=0; i<26; i++){
    node->alpha[i]=NULL;
  }
  return node;
}

void insert(tptr *head, char* str)
{
  tptr curr=*head;

  while(*str){
    if(curr->alpha[*str-'a']==NULL){
      curr->alpha[*str-'a']=newNode();
    }
    curr=curr->alpha[*str-'a'];
    str++;
  }
  curr->leaf=1;
}

int search(tptr head, char* str)
{
  if(head==NULL)return 0;

  tptr curr=head;

  while(*str){
    if(curr->alpha[*str-'a']!=NULL)printf("%c", *str);
    if(curr->alpha[*str-'a']==NULL){printf("\n"); return 0;}
    curr=curr->alpha[*str-'a'];
    str++;
  }
  printf("\n");
  return curr->leaf;
}

int children(tptr curr)
{
  for(int i=0; i<26; i++){
    if(curr->alpha[i]!=NULL)return 1;
  }
  return 0;
}

int deletion(tptr *curr, char* str)
{
  if(*curr==NULL)return 0;

  if(*str){
    if((*curr)->alpha[*str-'a']!=NULL && deletion(&((*curr)->alpha[*str-'a']), str+1) && (*curr)->leaf==0){
      if(!children(*curr)){
        free(*curr);
        *curr=NULL;
        return 1;
      }
      else{
        return 0;
      }
    }
  }
  if(*str=='\0' && (*curr)->leaf){
    if(!children(*curr)){
      free(*curr);
      *curr=NULL;
      return 1;
    }
    else{
      (*curr)->leaf=0;
      return 0;
    }
  }
}

int main()
{
  tptr head=newNode();
  insert(&head, "codeblooded");
  insert(&head, "cool");
  insert(&head, "foobar");
  printf("%d %d %d %d", search(head, "codeblooded"), search(head, "cool"), search(head, "foobar"), search(head, "codeorigins"));
  deletion(&head, "codeblooded");
  deletion(&head, "foobar");
  printf("%d %d %d %d", search(head, "codeblooded"), search(head, "cool"), search(head, "foobar"), search(head, "codeorigins"));

  return 0;
}
