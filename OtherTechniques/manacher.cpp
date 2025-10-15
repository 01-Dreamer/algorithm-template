#include<iostream>

using namespace std;
const int N=2e7+10;
int p[N];

string get_str(string& str)
{
    string res="#";
    for(char c:str) (res+=c)+='#';
    return res;
}

int manacher(string& str)
{
    p[0]=1;
    int mid=0,r=0;
    for(int i=1;i<str.size();i++)
    {
        if(i<=r) p[i]=min(p[2*mid-i],r-i+1);
        else p[i]=1;
        while(i-p[i]>=0&&i+p[i]<str.size()&&str[i-p[i]]==str[i+p[i]]) p[i]++;
        
        if(r<i+p[i]-1)
        {
            r=i+p[i]-1;
            mid=i;
        }
    }
    
    int res=0;
    for(int i=0;i<str.size();i++) res=max(res,(2*p[i]-1)/2);
    return res;
}

int main()
{
    string str;
    
    cin>>str;
    str=get_str(str);
    
    cout<<manacher(str);
    
    return 0;
}

