class Solution {
public:
    string baseNeg2(int n)
    {
        if(!n) return "0";
        const int base=-2;
        string res;
        while(n)
        {
            int r=n%base;
            n/=base;
            if(r<0) r-=base,n++;
            res+='0'+r;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};