class Solution {
public:
    int dp[200][200];
    int mini(int n,int m,vector<vector<int>>& grid)
    {
      if(n==0&&m==0)
      return grid[n][m];
      if(n<0||m<0)
      return 1e5;
      if(dp[n][m]!=0)
      return dp[n][m];
      int up=mini(n-1,m,grid)+grid[n][m];
      int left=mini(n,m-1,grid)+grid[n][m];
      return dp[n][m]=std::min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        return mini(n-1,m-1,grid);
    }
};