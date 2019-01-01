/*    &&&&      &               &     & & & &      &        &         & & & &
    &      &     &             &      &            &  &     &         &    &
    &      &      &     &     &       & &          &    &   &         &  &
    &      &       &  &   &  &        &            &      & &         &    &
      &&&&          &       &         & & & &      &        &    &    & & & &

    This code was solely produced by Owen Brake
*/

//Prevents header file from being declared more then once
#ifndef STRINGS_H
#define STRINGS_H

//Imports
#include <stdio.h>

//Function Prototypes
int str_len(char *);
int str_cmpy(char *,char*);
int palindrome(char *);
int str_ncmp(char *string1,char *string2,int n);

/*
  str_len(char*)
  Input:
    Takes in a string from which the length is calculated
  Output:
    Returns integer with length of the provided input string

  Summary:
    Takes in a string and calculates the length of provided string
*/
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

/*
  str_cmpy(char*, char*)
  Input:
    Two strings to compare against each other
  Output:
    An integer, one if first string is larger, 0 if strings are same, -1 if first string is smaller

  Summary:
    Determines which string is "larger", first based off length and if the lengths are the same the first character with a larger ASCII integer value then the other string makes the string larger
*/
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
/*
  str_ncmp(char* , char *,int)
  Input:
    Two strings to compare against each other and one integer as the length to compare
  Output:
    Integer representing which is larger, 0 is equivalent, 1 is the first string is larger, -1 is the second string is larger

  Summary:
    Compare two strings up to a certain length, goes through each character sequentially until the length n is reached or until a different character is found between the two strings if one is larger then the other then that string is the "larger" string
*/
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
/*
  palindrome(char*)
  Input:
    One string to determine if palindrome
  Output:
    Integer, returns 1 if string is a palindrome and 0 if it is not

  Summary:
    Determines if a string is a palindrome(symmetrical string)
*/
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

/*
  hasPrefix(char*,char*)
  Input:
    String representing the prefix
    String representing the string to compare
  Output:
    1 if the string has the prefix
    0 is the string does not contain the prefix
  Summary:
    Determines if a string contains another string as a prefix
*/
int hasPrefix(char *prefix,char *string){
  if(str_ncmp(prefix,string,str_len(prefix)) == 0){
    return 1;
  }
  return 0;
}


#endif
