#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) {
		for (int x = 1; x < (n - i + 1); x++) {
			printf(" ");
		}
		for (int x = 1; x < (i + 1); x++) {
			printf("#");
		}
		printf("\n");
	}
    return 0;
}
