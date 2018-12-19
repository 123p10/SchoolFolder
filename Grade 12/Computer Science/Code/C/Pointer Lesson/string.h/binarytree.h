#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

struct node

{

  char data;

  struct node *zero;

  struct node *one;

};

/* newNode() allocates a new node with the given data and NULL zero and

one pointers. */
struct node* addBranchForLetter(struct node* root,char letter,char *value);

struct node* newNode(char data)
{

  // Allocate memory for new node

  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node

  node->data = data;

  // Initialize zero and one children as NULL

  node->zero = NULL;

  node->one = NULL;

  return(node);

}

void pre_order_traversal(struct node* root) {

  if(root != NULL) {

    //printf("%d ",root->data);
    pre_order_traversal(root->zero);
    printf("%c ",root->data);
    pre_order_traversal(root->one);
    //printf("%d ",root->data);

  }

}

//User Code
//Error Checking still needed
struct node* constructBinaryTree(char* letters,char** values){
  struct node *root = newNode('\0');
  for(int i = 0;i < str_len(letters);i++){
    root = addBranchForLetter(root,letters[i],values[i]);
  }
  return root;
}
struct node* addBranchForLetter(struct node* root,char letter,char *value){
  struct node* ref = root;
//  printf("%s",value);
  for(int i = 0;i < str_len(value);i++){
    if(value[i] == '0'){
      if(ref->zero == NULL){
        ref->zero = newNode('\0');
      }
      ref = ref->zero;
    }
    if(value[i] == '1'){

      if(ref->one == NULL){
        ref->one = newNode('\0');
      }
      ref = ref->one;
    }
  }
  ref->data = letter;
  return root;
}
char getValueAtCode(struct node* root,char *string){
  for(int i = 0;i < str_len(string);i++){
    if(string[i] == '0'){
      if(root->zero == NULL){return '\0';}
      root = root->zero;
    }
    else if(string[i] == '1'){
      if(root->one == NULL){return '\0';}
      root = root->one;
    }
  }
  return root->data;
}

char* decodeString(char* inputString,char *letters,char **values,struct node* node){

  char *curr= (char*)calloc(250, sizeof(char));
  int count = 0;
  char value;
  for(int i = 0;i < str_len(inputString);i++){
    curr[count] = inputString[i];
    value = getValueAtCode(node,curr);
    //printf("%d",i);
    if(value != '\0'){
      printf("%c",value);
      curr = (char*)calloc(250, sizeof(char));
      count = 0;
    }
    else{count++;}
  }

}

#endif
