#include <bits/stdc+++.h>

int main(){
    int n,Sp=0,Ss=0,diff=0; 
    cin>>n;
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          cin>>a[a_i][a_j];
       }
    }
    for (int i=0;i<n;i++)
    {
        Sp=Sp+a[i][i];
        Ss=Ss+a[i][n-1-i];
    }
    diff=Sp-Ss;
    if (diff<0)
        diff=-1*diff;
    cout<<diff<<endl;
    return 0;
}
