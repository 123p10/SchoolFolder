#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "strings.h"
#include <string.h>
void promptForBinaryString(char *arr){
  printf("Please Input Your Binary String Now:");
  scanf("%s",arr);
  printf("\n");
}
int menuScreen(){
  int option = 0;
  printf("Hello and Welcome to Owen's Huffman Decoder\n\n");
  printf("Options:\n");
  printf("1) Decode a String\n");
  printf("2) Get the data of a tree\n");
  printf("3) Quit\n\n");
  printf("Answer: ");
  scanf("%d",&option);
  printf("\n");
  return option;
}
void getInputForHuffmanEncoding(char *letters,char* values[]){
  int num = 0;
  //values[0] = "HI";

  printf("How many codes do you want for your cipher?\n");
  scanf("%d",&num);
  for(int i = 0;i < num;i++){
    char temp[20] = "";
    printf("The %d char: ",i+1);
    scanf(" %c %s",&letters[i],&temp);
    printf("%s",temp);
    strcpy(values[i],temp);
    printf("%s",values[i]);
    printf("\n");
  }

}
char *typeToScanfModifier(char *type){
  if(str_cmpy(type,"int") == 0){return "%d";}
  if(str_cmpy(type,"char") == 0){return "%c";}
  if(str_cmpy(type,"string") == 0){return "%s";}
  return "%s";
}
#endif
