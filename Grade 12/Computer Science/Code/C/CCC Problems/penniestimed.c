#include <stdio.h>
#include <math.h>
#include <time.h>
int quadrant_count(int radius);

int main(void) {
  register double oldClock = (double)clock() ;
  register int radius = 2000;
  printf("%d",quadrant_count(radius));
  register double newClock = (double)clock() ;
  printf("It took %f s",(newClock - oldClock)/CLOCKS_PER_SEC);
  scanf("%d");
  return 0;
}

int quadrant_count(int radius)
{
  register int c,x = radius-1,y = radius-1,count=0;
  for(register int j=radius-1; j > 1; j--)
  {
    for(register int i=radius-1; i > 1; i--)
    {
      c = pow(x,2) + pow(y,2);
      if(pow(c,0.5) > radius) { count++; printf("%d %d\n",x,y);}
      y--;
    }
  y = radius - 1;
  x--;
  }
  return count*4;
}
int axis_count(int radius){
  return radius * 4 + 1;
}
/*


*/
