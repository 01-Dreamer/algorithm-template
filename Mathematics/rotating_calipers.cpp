#include <iostream>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N=50010;
int stk[N],top;
bool used[N];
PII p[N];
int n;


PII operator - (PII a,PII b)
{
    return {a.x-b.x,a.y-b.y};
}

int cross(PII a,PII b)
{
    return a.x*b.y-a.y*b.x;
}

int area(PII a,PII b,PII c)
{
    return cross(b-a,c-a);
}

int get_dist(PII a,PII b)
{
    int dx=a.x-b.x;
    int dy=a.y-b.y;
    return dx*dx+dy*dy;
}

void get_convex()
{
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        while(top>=2&&area(p[stk[top-2]],p[stk[top-1]],p[i])<=0)
        {
            if(area(p[stk[top-2]],p[stk[top-1]],p[i])<0)
                used[stk[--top]]=false;
            else top--;
        }
        stk[top++]=i;
        used[i]=true;
    }
    used[0]=false;

    for(int i=n-1;i>=0;i--)
    {
        if(used[i]) continue;
        while(top>=2&&area(p[stk[top-2]],p[stk[top-1]],p[i])<=0)
            used[stk[--top]]=false;
        stk[top++]=i;
        used[i]=true;
    }
    top--;
}

int rotating_calipers()
{
    if (top<=2) return get_dist(p[0],p[n-1]);

    int res=0;
    for (int i=0,j=2;i<top;i++)
    {
        auto d=p[stk[i]],e=p[stk[i+1]];
        while(area(d,e,p[stk[j]])<area(d,e,p[stk[j + 1]])) j=(j+1)%top;
        res=max(res,max(get_dist(d,p[stk[j]]),get_dist(e,p[stk[j]])));
    }
    return res;
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
    get_convex();
    printf("%d\n",rotating_calipers());

    return 0;
}
