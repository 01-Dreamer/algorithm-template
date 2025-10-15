#include<iostream>

using namespace std;
const int N=1010;
int s[N][N];
int n,m,q;

void insert(int x1,int y1,int x2,int y2,int v)
{
    s[x1][y1]+=v;
    s[x2+1][y1]-=v;
    s[x1][y2+1]-=v;
    s[x2+1][y2+1]+=v;
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    int x;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
           scanf("%d",&x);
           insert(i,j,i,j,x);
       }
       
    int x1,y1,x2,y2,v;
    while(q--)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
        insert(x1,y1,x2,y2,v);
    }
    
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i-1][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]+=s[i][j-1];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
           printf("%d ",s[i][j]);
        puts("");   
    }

    
    return 0;
}