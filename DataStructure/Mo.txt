#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=50010,M=2e5+10,K=1000010;
int w[N],cnt[K];

int n,m,len;
int get(int i)
{
    return i/len;
}


struct Query
{
    int id,l,r;

    bool operator < (const Query& t) const
    {
        int ID1=get(l),ID2=get(t.l);
        if(ID1!=ID2) return ID1<ID2;
        return r<t.r;
    }

}q[M];
int ans[M];

void add(int x,int& res)
{
    if(!cnt[x]) res++;
    cnt[x]++;

}

void del(int x,int& res)
{
    cnt[x]--;
    if(!cnt[x]) res--;

}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    scanf("%d",&m);
    len=max((int)sqrt((double)n*n/m),1);

    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[i]={i,l,r};
    }

    sort(q,q+m);

    int L=1,R=1;
    int res=1;
    cnt[w[1]]++;
    for(int i=0;i<m;i++)
    {
        int id=q[i].id,l=q[i].l,r=q[i].r;

        while(L<l) del(w[L++],res);
        while(L>l) add(w[--L],res);
        while(R<r) add(w[++R],res);
        while(R>r) del(w[R--],res);

        ans[id]=res;
    }


    for(int i=0;i<m;i++) printf("%d\n",ans[i]);


    return 0;
}