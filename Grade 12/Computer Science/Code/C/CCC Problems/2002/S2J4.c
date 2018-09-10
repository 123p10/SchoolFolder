#include <stdio.h>


/*
This function finds the greatest number that when multiplied to the numerator will result in an integer that is less then the denominator
*/
int multiple(int num, int den);
int gcd(int numerator,int denominator);



int main(void) {

  //  I/O
  int numerator, denominator;
  printf("Enter a positive integer for the numerator ");
   scanf("%d", &numerator);
  printf("Enter a positive integer for the denominator ");
  scanf("%d", &denominator);
  printf("\n");
  if(numerator != 0){
    //Calculate the first multiple
    int gcf = gcd(numerator,denominator);
    //Output
    int numo = numerator/gcf;
    int deno = denominator/gcf;
    if(deno == 1){
      printf("%d",numo);
    }
    else{
      printf("%d  %d / %d",numo/deno,numo - (numo/deno)*deno,deno);
    }
  }
  else{
    printf("0");
  }
  //End Program
  return 0;
}
int multiple(int num, int den)
{
 int a = 1;
 while( a*num <= den ) a++;
 return a-1;
}
int gcd(int numerator,int denominator){
  int remainder;
  int a = multiple(numerator, denominator);

  //Euclids algorithim breaks out when it reachs 0 so the while loop breaks when this happens
  while ((denominator - a*numerator) != 0)
  {
    //This is Euclids method
    //denominator = numerator * a + remainder
    //thus
    //remainder = denominator - numerator*a
    remainder = denominator - a*numerator;

    //We then reset the values to call multiple again and loop
    denominator = numerator;
    numerator = remainder;
    //Calculate the next multiple
    a = multiple(numerator, denominator);
  }
  return numerator;
}
