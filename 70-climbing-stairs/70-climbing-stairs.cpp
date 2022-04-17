class Solution {
public:
    int a[46]={0};
    int climbStairs(int n) 
    {
        if(a[n]!=0)
            return a[n];
        int p=0;
        int q=0;
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        p=climbStairs(n-1);
        if(n>1)
        q=climbStairs(n-2);
        return a[n]=p+q;
    }
};