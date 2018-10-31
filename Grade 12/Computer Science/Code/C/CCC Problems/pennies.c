#include <stdio.h>
#include <math.h>

int quadrant_count(int radius);

int main(void) {
  int radius = 27;
  printf("%d",quadrant_count(radius));
  return 0;
}

int quadrant_count(int radius)
{
  int c,x = radius-1,y = radius-1,count=0;
  for(int j=radius-1; j > 1; j--)
  {
    for(int i=radius-1; i > 1; i--)
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
