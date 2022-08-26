class Solution {
public:
    int dp[100][100][100];
    int helper(int i,int j1,int j2,vector<vector<int>>& grid)
    {
        if(j1<0||j2<0||j1==grid[0].size()||j2==grid[0].size())
        return -1e8;
        if(i==grid.size()-1&&j1==j2)
        return grid[i][j1];
        if(i==grid.size()-1)
        return grid[i][j1]+grid[i][j2];
        if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        int maxi=0;
        for(int dj1=-1;dj1<2;dj1++)
        {
            for(int dj2=-1;dj2<2;dj2++)
            {
                if(j1==j2)
                {
                    maxi=max(maxi,grid[i][j1]+helper(i+1,j1+dj1,j2+dj2,grid));
                }
                else
                {
                    maxi=max(maxi,grid[i][j2]+grid[i][j1]+helper(i+1,j1+dj1,j2+dj2,grid));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
            
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,grid[0].size()-1,grid);     
    }
};