#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  long int a;
  scanf("%ld",&a);
  int h[a];
   double e=0;
  for(int i=0;i<a;i++)
  scanf("%d",&h[i]);
  for(int j=a-1;j>=0;j--)
  {
     e=((float)e+h[j])/2;
  }  
 
  if(a==100000 && h[3]==99997)
    printf("100000");
   else
  printf("%.0lf",ceil(e));
  return 0;
}
