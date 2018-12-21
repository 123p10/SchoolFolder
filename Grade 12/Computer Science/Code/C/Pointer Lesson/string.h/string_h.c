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
  int num = 0;
  char *letters = (char*)calloc(20, sizeof(char));
  char values[20][50] = (char[][])calloc(20*50, sizeof(char));

  printf("How many codes do you want for your cipher?\n");
  scanf("%d",&num);
  for(int i = 0;i < num;i++){
    printf("The %d char: ",i+1);
    scanf(" %c",&letters[i]);
    scanf("%s",values[i]);
    printf("%d",&values[i][0]));
    printf("\n");
  }

//  getInputForHuffmanEncoding(&letters,&values,num);
  printf("input made");
  printf("%s",values[0]);
  struct node* node = constructBinaryTree(letters,values);
  //printf("tree made");
  decodeString("0111",letters,values,node);
  //printf("string made");

//  pre_order_traversal(node);
}
