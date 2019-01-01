/*    &&&&      &               &     & & & &      &        &         & & & &
    &      &     &             &      &            &  &     &         &    &
    &      &      &     &     &       & &          &    &   &         &  &
    &      &       &  &   &  &        &            &      & &         &    &
      &&&&          &       &         & & & &      &        &    &    & & & &

    This code was soley produced by Owen Brake
*/



//Prevent header file from being declared more then once
#ifndef UI_H
#define UI_H


//Imports
#include <stdio.h>
#include "strings.h"
#include <string.h>

//Necessary Function Prototypes
void inputTree(int* n,char** l,char* (v[][50]));

/*
  printLine(char*)
  Input:
    String to print
  Output: None

  Summary:
    Prints the provided string with a new line at the end of it
*/
void printLine(char * input){
  printf("%s\n",input);
}

/*
  promptForBinaryString(char*)
  Input:
    One pointer to a string
  Output: None

  Summary:
    Takes the pointer to a string and sets that string to the input
*/

void promptForBinaryString(char **str1_ptr)
{
  printLine("Now Please Input the Code to Decode");
  char *temp = calloc(50,sizeof(char));
  scanf("%s",temp);
	*str1_ptr = temp;
}

/*
  menuScreen()
  Input: None
  Output:
    Integer representing the choice made by the user

  Summary:
    Prints out the Menu Screen and return the input from the user
*/
int menuScreen(){
  int option = 0;
  printLine("Hello and Welcome to Owen's Huffman Decoder");
  printLine("");
  printLine("Options:");
  printLine("1) Decode a String");
  printLine("2) Get the data of a tree");
  printLine("3) Quit");
  printLine("");
  printf("Answer: ");
  scanf("%d",&option);
  printLine("");
  return option;
}

/*
  decodeHuffmanString()
  Input: None
  Output: None

  Summary:
    This function is essentially the main function for decoding the Huffman String, it calls the functions to get the inputs
    and it calls the functions to deal with the outputs
*/
void decodeHuffmanString(){

  //Initialize Variables
  char *stringToDecode;
  int num = 0;
  char *letters = (char*)calloc(30,sizeof(char));
  char values[26][50] = {};


  //Get Inputs
  inputTree(&num,&letters,&values);
  //Error Check
  prefixErrorCheck(letters,values);
  //Create Binary Tree
  struct node* node = constructBinaryTree(letters,values);
  //Get Binary String
  promptForBinaryString(&stringToDecode);
  printLine("");
  printf("The Decoded String is: ");
  //Output
  decodeString(stringToDecode,node);
  printLine("");
}

/*
  inputTree(int*,char**,char*([][]))
  Input:
    Pointer to an integer, representing the number of codes to eb inputted
    Pointer to string, representing the letters corresponding to the binary codes
    Pointer to array of strings, representing the binary codes corresponding to the letters
  Output: None

  Summary:
  Takes in pointers to the variables to change, asks for input for creating a binary tree, the letter codes, the binary codes and the number of codes
*/
void inputTree(int* n,char** l,char* (v[][50])){
  int num = 0;
  char *letters = (char*)calloc(30,sizeof(char));
  char values[26][50] = {};
  printLine("How many codes do you want for your cipher?");
  scanf("%d",&num);
  for(int i = 0;i < num;i++){
    printLine("Values");
    scanf(" %c",letters+i);
    scanf("%s",(values+i));
    printLine("");
  }
  *l = letters;
  memcpy(*v,values,50*26*sizeof(char));
  *n = num;
}

/*
  binaryTreeCreator()
  Input: None
  Output: None

  Summary:
  Takes in input and generates a binary tree from it, then outputs the pre order traversal of the tree
*/
void binaryTreeCreator(){
  int num = 0;
  char *letters = (char*)calloc(30,sizeof(char));
  char values[26][50] = {};
  inputTree(&num,&letters,&values);
  struct node* node = constructBinaryTree(letters,values);
  printLine("The Preorder Traversal for your tree is:");
  pre_order_traversal(node);
}
/*
  continueChoice()
  Input: None
  Output:
    Integer representing the choice provided by the input
  Summary:
    Provides a user interface giving the user the option to quit or goto
    the main menu
*/
int continueChoice(){
  int choice = 0;
  printLine("");
  printLine("Would you like to continue?");
  printLine("0: Main Menu");
  printLine("1: Quit");
  printf("Choice: ");
  scanf("%d",&choice);
  return choice;
}
#endif
