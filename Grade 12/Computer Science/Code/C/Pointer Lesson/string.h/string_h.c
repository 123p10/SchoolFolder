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
        decodeHuffmanString();
        break;
      case 2:
        binaryTreeCreator();
        break;
      case 3:
        printLine("Thank you for running my program");
        return 1;
    }
    if(continueChoice() == 1){printLine("Thank you for running my program");return 0;}
  }
  return 0;
}
