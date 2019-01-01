/*    &&&&      &               &     & & & &      &        &         & & & &
    &      &     &             &      &            &  &     &         &    &
    &      &      &     &     &       & &          &    &   &         &  &
    &      &       &  &   &  &        &            &      & &         &    &
      &&&&          &       &         & & & &      &        &    &    & & & &

    This code was produced by Owen Brake with portions borrowed from Shaun Knowles' Binary Tree Example Code
*/


//Prevents this file from being defined more then once
#ifndef BINARY_TREE
#define BINARY_TREE

//Imports
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

//Node object for the binary tree
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
    pre_order_traversal(root->zero);
    printf("%c ",root->data);
    pre_order_traversal(root->one);
  }

}

//Beginning of Owen's Code

/*
  constructBinaryTree(char*,char[][])
  Input:
    String of letters representing the char codes
    Array of Strings representing the binary codes
  Output:
    Root node of the tree

  Summary:
    Takes in the necessary inputs to create a binary tree with the binary codes repsenting where on the tree the letters are to be placed
*/
struct node* constructBinaryTree(char* letters,char values[26][50]){
  struct node *root = newNode('\0');
  for(int i = 0;i < str_len(letters);i++){
    root = addBranchForLetter(root,letters[i],&(values[i]));
  }
  return root;
}

/*
  addBranchForLetter(struct node*, char,char*)
  Input:
    Root node of tree to branch down from
    Character representing the letter to be placed on the tree
    String representing the binary code
  Output:
    Root Node of the tree after branch added

  Summary:
    Place the letter on the tree given based on the location given in the input value
*/
struct node* addBranchForLetter(struct node* root,char letter,char *value){
  struct node* ref = root;
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

/*
  getValueAtCode(struct node*,char*)
  Input:
    Root Node of tree
    String representing where on the tree to search
  Output:
    Character found on tree
  Summary:
    Gets the value of a node at a given location on a binary tree based on the binary code provided
*/
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
/*
  decodeString(char*,struct node*)
  Input:
    String representing the binary code to decode
    The root node of the tree to search through
  Output:
    String representing the decoded string
  Summary:
    Decode a Huffman Binary Sequence and outputs the decoded string
*/
char* decodeString(char* inputString,struct node* node){

  char *curr= (char*)calloc(250, sizeof(char));
  int count = 0;
  char value;
  for(int i = 0;i < str_len(inputString);i++){
    curr[count] = inputString[i];
    value = getValueAtCode(node,curr);
    if(value != '\0'){
      printf("%c",value);
      curr = (char*)calloc(250, sizeof(char));
      count = 0;
    }
    else{count++;}
  }

}
/*
  prefixErrorCheck(char*,char [][])
  Input:
    String of all the letters for the tree
    Array of strings for the binary codes to compare
  Output: None
  Summary:
    Check all the binary codes and throw an error if one of the strings is a
    prefix of another
*/
void prefixErrorCheck(char* letters,char values[26][50]){
  for(int i = 0;i < str_len(letters);i++){
    for(int j = 0;j < str_len(letters);j++){
      if(hasPrefix(values[i],values[j]) && i != j){
        printf("ERROR: %s will never be used as it has the prefix %s\n",values[j],values[i]);
      }
    }
  }
}

#endif
