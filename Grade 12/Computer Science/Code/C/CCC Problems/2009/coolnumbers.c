//COMPLETE
#include <stdio.h>
#include <math.h>

int main(void){
  int bot,top;
  printf("Input the bottom range\n");
  scanf("%d",&bot);
  printf("Input the top range\n");
  scanf("%d",&top);
  printf("\n");
  int count = 0;
  int three = cbrt(bot);
  if(ceilf(cbrt(bot)) != cbrt(bot)){
    three = cbrt(bot) + 1;
  }
  int cube = three*three*three;

  while(cube <= top){
    if(sqrt(cube) == ceilf(sqrt(cube))){
      count++;
    }
    three++;
    cube = three*three*three;
  }
  printf("\n There are %d cool numbers",count);
}
