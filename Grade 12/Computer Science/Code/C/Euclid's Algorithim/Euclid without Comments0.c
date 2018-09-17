#include <stdio.h>


int multiple(int num, int den);
int gcd(int numerator,int denominator);



int main(void) {
  int numerator, denominator;
  printf("Enter a positive integer for the numerator ");
  scanf("%d", &numerator);
  printf("Enter a positive integer for the denominator ");
  scanf("%d", &denominator);
  printf("\n");
  int gcf = gcd(numerator,denominator);
  printf("GCF: %d \n\n",gcf);
  printf("%d / %d",numerator/gcf,denominator/gcf);
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
  while ((denominator - a*numerator) != 0)
  {
    remainder = denominator - a*numerator;
    denominator = numerator;
    numerator = remainder;
    a = multiple(numerator, denominator);
  }
  return numerator;
}
