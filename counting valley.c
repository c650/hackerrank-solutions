#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, x=0;

    scanf("%d", &n);

    char a[n];
    int b[n];

    scanf("%s", a);


    for(i=0;i<n;i++)
    {
        if(a[i]=='U'){
            x++;
            b[i]=x;
        }
        else
        {
            x--;
            b[i]=x;
        }
    }

    x=0;

    for(i=0;i<n;i++)
    {
        if(b[i]<0 && b[i+1]==0)   //checking number is negative, and when reach to next position it becomes zero, then valley created
            x++;
    }

    printf("%d", x);

    return 0;
}
