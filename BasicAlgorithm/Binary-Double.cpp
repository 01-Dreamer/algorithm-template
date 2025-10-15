#include<iostream>

using namespace std;


int main()
{
    double a;
    cin>>a;
    
    double l=-10000,r=10000;
    while(r-l>1e-8)
    {
        double mid=(l+r)/2.0;
        
        if(mid*mid*mid<a) l=mid;
        else r=mid;
    }
    
    printf("%.6lf",l);
    
    
    return 0;
}