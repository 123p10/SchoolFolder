/*    &&&&      &               &     & & & &      &        &         & & & &
    &      &     &             &      &            &  &     &         &    &
    &      &      &     &     &       & &          &    &   &         &  &
    &      &       &  &   &  &        &            &      & &         &    &
      &&&&          &       &         & & & &      &        &    &    & & & &

    This code was solely produced by Owen Brake
*/



//TODO ERROR CHECKING
//TODO COMMENTS


//Imports
#include <stdio.h>
#include "strings.h"
#include "binarytree.h"
#include "userinterface.h"

//Main Function
int main(void) {
  while(1){
    int option = menuScreen();
    switch(option){
      case 1:
        //Convert Binary Code into ASCII Sequence
        decodeHuffmanString();
        break;
      case 2:
        //Create a binary tree and do pre order traversal
        binaryTreeCreator();
        break;
      case 3:
        //Quit program
        printLine("Thank you for running my program");
        return 1;
    }
    //Check whether user has chosen to continue after program has finished
    if(continueChoice() == 1){printLine("Thank you for running my program");return 0;}
  }
  return 0;
}
