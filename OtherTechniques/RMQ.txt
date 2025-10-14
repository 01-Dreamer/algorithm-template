#include <iostream>
#include <cmath>

using namespace std;
const int N=2e5+10,M=18;
int w[N],f[N][M];
int n,m;

void init()
{
    for(int j=0;j<M;j++)
       for(int i=1;i+(1<<j)-1<=n;i++)
          if(!j) f[i][j]=w[i];
          else f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
}

int query(int l,int r)
{
    int len=r-l+1;
    int k=log(len)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    
    init();
    
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    
    
    return 0;
}