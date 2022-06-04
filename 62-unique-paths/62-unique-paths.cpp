class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) 
    {
        if(n<1||m<1)
        return 0;
        if(dp[m][n]!=0)
        return dp[m][n];
        if(n==1&&m==1)
        return 1;
        int up=uniquePaths(m-1,n);
        int left=uniquePaths(m,n-1);
        return dp[m][n]=left+up;
    }
};