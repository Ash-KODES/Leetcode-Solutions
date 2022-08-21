class Solution {
public:
    int mySqrt(int x) 
    {
        if(x==0)
        return 0;
        
        long long int lo=1;
        long long int hi=x;
        while(hi-lo>1)
        {
            long long int mid=(hi+lo)/2;
            long long val=mid*mid*1LL;
            if(val>x)
            hi=mid-1;
            else
            lo=mid;
        }
        long long val=hi*hi*1LL;
        if(val<x)
        return hi;
        else
        return lo;
        
    }
};