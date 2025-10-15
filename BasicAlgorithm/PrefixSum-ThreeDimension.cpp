#include<iostream>

using namespace std;
const int N=110;
int s[N][N][N];
int n,q;


int main()
{
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=n;k++)
             scanf("%d",&s[i][j][k]);
    
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=n;k++)
             s[i][j][k]+=s[i-1][j][k];
             
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=n;k++)
             s[i][j][k]+=s[i][j-1][k];         
    
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          for(int k=1;k<=n;k++)
             s[i][j][k]+=s[i][j][k-1];
    
    scanf("%d",&q);
    
    int l1,r1,l2,r2,l3,r3;//x1 x2 y1 y2 z1 z2
    while(q--)
    {
        scanf("%d%d%d%d%d%d",&l1,&r1,&l2,&r2,&l3,&r3);
        int res=s[r1][r2][r3]
               -s[l1-1][r2][r3]-s[r1][l2-1][r3]-s[r1][r2][l3-1]
               +s[l1-1][l2-1][r3]+s[l1-1][r2][l3-1]+s[r1][l2-1][l3-1]
               -s[l1-1][l2-1][l3-1];
        
        printf("%d\n",res);
    }
    
    
    return 0;
}