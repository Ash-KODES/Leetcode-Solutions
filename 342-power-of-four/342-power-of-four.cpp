class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        int c=0;
        if(n<=0)
        return 0;
        while(n%2==0)
        {
            c++;
            n/=2;
        }
        if(n==1&&c%2==0)
        return 1;
        else
        return 0;
    }
};