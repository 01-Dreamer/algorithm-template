#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const double eps=1e-8;


double f(double x)
{
    return sin(x) / x;
}

double simpson(double l,double r)
{
    double mid=(l+r)/2;
    return (f(l)+4*f(mid)+f(r))*(r-l)/6;
}


double asr(double l,double r,double s)
{
    double mid=(l+r)/2;
    
    double L=simpson(l,mid),R=simpson(mid,r);
    if(fabs(L+R-s)<eps) return L+R;
    return asr(l,mid,L)+asr(mid,r,R);
    
}


int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("%.6lf",asr(a,b,simpson(a,b)));
    
    
    return 0;
}