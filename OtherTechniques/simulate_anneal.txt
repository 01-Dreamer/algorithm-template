#include<iostream>
#include<ctime>
#include<cmath>


#define x first
#define y second

using namespace std;
typedef pair<double,double> PDD;
const int N=110;
PDD p[N];
double ans=1e9;
int n;

double rand(double l,double r)
{
    return (double) rand()/RAND_MAX*(r-l)+l;
}

double get_dist(PDD a,PDD b)
{
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

double calc(PDD point)
{
    double res=0;
    for(int i=0;i<n;i++)
        res+=get_dist(point,p[i]);
    ans=min(ans,res);
    return res;
}

void simulate_anneal()
{
    PDD cur_p(rand(0,10000),rand(0,10000));
    for(double t=1e4;t>=1e-4;t*=0.99)
    {
        PDD new_p(rand(cur_p.x-t,cur_p.x+t),rand(cur_p.y-t,cur_p.y+t));
        double dt=calc(new_p)-calc(cur_p);
        if(exp(-dt/t)>rand(0,1)) cur_p=new_p;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    
    int T=100;
    while(T--) simulate_anneal();
    
    printf("%d",(int)(ans+0.5));
    
    
    return 0;
}
