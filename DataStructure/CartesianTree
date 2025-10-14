#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=1e7+10;
struct Node
{
    int l,r;
}tr[N];
int stk[N],top;
int p[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        int last=0;
        while(top&&p[stk[top]]>p[i]) last=stk[top--];
        if(top) tr[stk[top]].r=i;
        if(last) tr[i].l=last;
        stk[++top]=i;
    }

    LL A=0,B=0;
    for(int i=1;i<=n;i++)
    {
        A^=(LL)i*(tr[i].l+1);
        B^=(LL)i*(tr[i].r+1);
    }
    printf("%lld %lld\n",A,B);

    return 0;
}

