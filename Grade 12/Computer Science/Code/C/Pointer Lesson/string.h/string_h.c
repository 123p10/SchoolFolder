#include <stdio.h>
#include "strings.h"
#include "binarytree.h"
#include "userinterface.h"
//Make sure to add comments

void decodeHuffmanString();


int main(void) {
  int option = menuScreen();
  switch(option){
    case 1:
      decodeHuffmanString();
      break;
    case 2:
      printf("TBD");
      break;
    case 3:
      return 1;
  }

  printf("\nNo Errors");
  return 0;
}

void decodeHuffmanString(){
  char letters[20];
  char *values[20] = {"A","B"};
  getInputForHuffmanEncoding(letters,values);

  printf("input made");
  printf("%s",values[0]);
  struct node* node = constructBinaryTree(letters,values);
  //printf("tree made");
  decodeString("0111",letters,values,node);
  //printf("string made");

//  pre_order_traversal(node);
}
