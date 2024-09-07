#include<iostream>

using namespace std;
const int N=1010;
int s[N][N];
int n,m,q;


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          scanf("%d",&s[i][j]);
          
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i-1][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i][j-1];
    
    int l1,r1,l2,r2;
    while(q--)
    {
        scanf("%d%d%d%d",&l1,&l2,&r1,&r2);// x1 y1 x2 y2
        int res=s[r1][r2]-s[l1-1][r2]-s[r1][l2-1]+s[l1-1][l2-1];
        printf("%d\n",res);
    }
    
    
    return 0;
}