#include<iostream>

using namespace std;
const int N=1010;
int tr[N][N];
int n,m,q;

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int y,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
       for(int j=y;j<=m;j+=lowbit(j))
          tr[i][j]+=v;
}

int query(int x,int y)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
       for(int j=y;j>=1;j-=lowbit(j))
          res+=tr[i][j];
    return res;
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    int x;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          {
              scanf("%d",&x);
              add(i,j,x);
          }
    
    int x1,y1,x2,y2;
    while(q--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int res=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
        printf("%d\n",res);
    }
    
    
    return 0;
}