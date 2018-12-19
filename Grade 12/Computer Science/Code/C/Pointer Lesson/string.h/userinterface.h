#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "strings.h"
void promptForBinaryString(char *arr){
  printf("Please Input Your Binary String Now:");
  scanf("%s",arr);
  printf("\n");
}
char *typeToScanfModifier(char *type){
  if(str_cmpy(type,"int") == 0){return "%d";}
  if(str_cmpy(type,"char") == 0){return "%c";}
  if(str_cmpy(type,"string") == 0){return "%s";}
  return "%s";
}
#endif
