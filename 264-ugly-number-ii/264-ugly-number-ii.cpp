class Solution {
public:
    int nthUglyNumber(int n) {
        int x2=0;
        int x3=0;
        int x5=0;
        int a[n];
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            int mini=min(min(2*a[x2],3*a[x3]),5*a[x5]);
            if(mini==2*a[x2])
            x2++;
            if(mini==3*a[x3])
            x3++;
            if(mini==5*a[x5])
            x5++;
            a[i]=mini;
        }
        return a[n-1];
    }
};