#include <stdio.h>

int main(void){
  int input = 0;
  printf("Enter a digit between 0 and 9 ");
  scanf("%d",&input);
  int numbers[10][8] = {
    {1,1,0,1,1,1,1},
    {0,1,0,1,0,0,0},
    {1,1,1,0,1,1,0},
    {1,1,1,1,1,0,0},
    {0,1,1,1,0,0,1},
    {1,0,1,1,1,0,1},
    {1,0,1,1,1,1,1},
    {1,1,0,1,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,1,0,1}
  };
  if(numbers[input][0] == 1){
    printf(" *** ");
  }
  printf("\n");
  if(numbers[input][1] == 1 && numbers[input][6]){
    printf("*   *\n");
    printf("*   *\n");
    printf("*   *\n");
  }
  else if(numbers[input][1] == 1){
    printf("    *\n");
    printf("    *\n");
    printf("    *\n");
  }
  else if(numbers[input][6]){
    printf("*\n");
    printf("*\n");
    printf("*\n");
  }
  if(numbers[input][2]){
    printf(" *** \n");
  }
  else{
    printf("\n");
  }
  if(numbers[input][3] == 1 && numbers[input][5]){
    printf("*   *\n");
    printf("*   *\n");
    printf("*   *\n");
  }
  else if(numbers[input][3] == 1){
    printf("    *\n");
    printf("    *\n");
    printf("    *\n");
  }
  else if(numbers[input][5]){
    printf("*\n");
    printf("*\n");
    printf("*\n");
  }
  if(numbers[input][4]){
    printf(" *** \n");
  }
  return 0;

}
