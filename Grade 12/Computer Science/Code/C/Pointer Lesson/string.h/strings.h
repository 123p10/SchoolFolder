#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
int str_len(char *);
int str_cmpy(char *,char*);
int palindrome(char *);
int str_ncmp(char *string1,char *string2,int n);
int str_len(char *string){
  char *ptr;
  ptr = NULL;
  ptr = string;
  int i;
  if(ptr == NULL){
    return -1;
  }
  for(i = 0;;i++){
    if(*(string+i) == '\0' ){
      break;
    }
  }
  return i;
}
int str_cmpy(char *first, char *second){
  int first_length = str_len(first);
  int second_length = str_len(second);
  if(first_length > second_length){
    return 1;
  }
  else if(first_length < second_length){
    return -1;
  }
  for(int i = 0;i < first_length;i++){
    if(*(first+i) > *(second+i)){
      return 1;
    }
    if(*(first+i) < *(second+i)){
      return -1;
    }
  }
  return 0;
}
int str_ncmp(char *string1,char *string2,int n){
  for(int i = 0;i < n;i++){
    if(*(string1+i) > *(string2+i)){
      return 1;
    }
    if(*(string1+i) < *(string2+i)){
      return -1;
    }
  }
  return 0;
}
int palindrome(char *string){
  int palindrome = 1;
  int stringLength = str_len(string);
  for(int j = 0;j < (stringLength)/2-1;j++){
    if(*(string+j) != *(string+stringLength-j-1)){
      palindrome = 0;
    }
  }
  return palindrome;
}
#endif
