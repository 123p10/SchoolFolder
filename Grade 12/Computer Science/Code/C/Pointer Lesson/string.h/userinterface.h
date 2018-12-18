#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "strings.h"
void mainInput(){
  char *inputString = "110101010111110101111110";
  char letters[20] = {'C','B','A','F'};
  char *values[20] = {"0","111","11010","10"};
  char *curr= (char*)calloc(250, sizeof(char));
  struct node* node = constructBinaryTree(letters,values);
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
char *typeToScanfModifier(char *type){
  if(str_cmpy(type,"int") == 0){return "%d";}
  if(str_cmpy(type,"char") == 0){return "%c";}
  if(str_cmpy(type,"string") == 0){return "%s";}
  return "%s";
}
#endif
