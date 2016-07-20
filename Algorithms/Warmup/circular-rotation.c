#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int main() {
    int n,k,q;
    scanf("%i %i %i", &n, &k, &q);
    k %= n;
   
    int arr[n], i;
    for (i = 0; i < n; i++) {
        scanf("%i", arr+i);
    }
   
    int m;
    for (i = 0; i < q; i++) {
        scanf("%i", &m);
        printf("%i\n", arr[m - k >= 0 ? m-k : m-k+n]);
    }
   
    return 0;
}
