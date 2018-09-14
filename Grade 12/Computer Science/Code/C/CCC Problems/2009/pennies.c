//COMPLETE FULL EFFIENCY BITCH

#include <stdio.h>
#include <math.h>

int main(void){
  int range = 0;
  printf("Input the numbers\n");
  int count = 0;
  while(1){
    int radius = 0;
    scanf("%d",&radius);
    if(radius == 0){
      break;
    }

    for(int x = 1;x <= radius;x++){
      count += sqrt(radius * radius - x * x);
    }
    printf("\n%d\n",count*4 + radius*4+1);
    count = 0;
  }
}
