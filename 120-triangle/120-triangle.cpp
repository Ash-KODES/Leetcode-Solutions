class Solution {
public:
    int dp[1000][1000];
    int helper(vector<vector<int>>& triangle,int i,int j)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }  
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=triangle[i][j]+helper(triangle,i+1,j+1);
        int diagonal=triangle[i][j]+helper(triangle,i+1,j);
        return dp[i][j]=min(up,diagonal);
        }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(triangle,0,0);
    }
};

