#include <stdio.h>
#include "strings.h"
#include "binarytree.h"
#include "userinterface.h"
//Make sure to add comments

int main(void) {
  char* arr = "bonjour";
  promptForBinaryString(arr);
  printf("%s",arr);
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
  return 0;
}
