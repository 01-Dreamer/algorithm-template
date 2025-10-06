#include<iostream>
#include<cmath>

using namespace std;
const int N=110;
int a[N][N];
int n;

int gauss()
{
    int r,c;
    for(r=c=0;c<n;c++)
    {
        int t=-1;
        for(int i=r;i<n;i++)
           if(a[i][c])
           {
               t=i;
               break;
           }
        
        if(t==-1) continue;
        
        for(int i=c;i<=n;i++) swap(a[r][i],a[t][i]);
        for(int i=r+1;i<n;i++)
           if(a[i][c])
              for(int j=c;j<=n;j++)
                 a[i][j]^=a[r][j];
        
        r++;
    }
    
    if(r<n)
    {
        for(int i=r;i<n;i++)
           if(a[i][n]) return 1;
        return 2;   
    }
    
    for(int i=n-2;i>=0;i--)
       for(int j=i+1;j<n;j++)
          a[i][n]^=a[i][j]*a[j][n];
    
    return 0;
}


int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
       for(int j=0;j<n+1;j++)
          scanf("%d",&a[i][j]);
          
    int t=gauss();
    
    if(t==1) puts("No solution");
    else if(t==2) puts("Multiple sets of solutions");
    else
    {
        for(int i=0;i<n;i++)
           printf("%d\n",a[i][n]);
    }
    
          
    return 0;
}

//////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;
const int N=2010;
bitset<N> a[N];
int n,m,p;
int pos[N];
int B[N][N];

int gauss()
{
    memset(pos,-1,sizeof(pos));
    int r,c;
    for(r=c=0;c<m;c++)
    {
        int t=-1;
        for(int i=r;i<n;i++)
           if(a[i][c])
           {
               t=i;
               break;
           }
        if(t==-1) continue;
        swap(a[r],a[t]);
        pos[c]=r;
        for(int i=r+1;i<n;i++)
           if(a[i][c]) a[i]^=a[r];
        r++;
    }
    
    for(int i=r;i<n;i++)
       for(int j=m;j<m+p;j++)
          if(a[i][j]) return 1;

    static bitset<N> x[N];
    for(int i=0;i<m;i++) x[i].reset();

    for(int i=m-1;i>=0;i--)
    {
        if(pos[i]==-1) continue;
        bitset<N> rhs=a[pos[i]];
        for(int j=i+1;j<m;j++)
            if(pos[j]!=-1 && a[pos[i]][j]) rhs^=x[j];
        for(int t=0;t<m;t++) rhs[t]=0;
        x[i]=rhs;
    }

    for(int i=0;i<m;i++)
       for(int j=0;j<p;j++)
           B[i][j]=x[i][m+j];

    if(r<m) return 2;
    return 0;
}

int main()
{
    cin>>n>>m>>p;
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
       {
           int x;
           cin>>x;
           a[i][j]=x;
       }
    for(int i=0;i<n;i++)
      for(int j=0;j<p;j++)
      {
          int x;
          cin>>x;
          a[i][m+j]=x;
      }
          
    int t=gauss();
    if(t==1) puts("No solution");
    else
    {
        if(t==2) puts("Multiple sets of solutions");
        for(int i=0;i<m;i++)
            for(int j=0;j<p;j++)
                cout<<B[i][j]<<(j==p-1?'\n':' ');
        
    }
          
    return 0;
}
