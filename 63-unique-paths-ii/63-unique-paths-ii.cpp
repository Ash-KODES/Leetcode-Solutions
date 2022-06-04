class Solution {
public:
    int dp[100][100];
    int paths(int n,int m,vector<vector<int>>& obstacleGrid)
    {
      if(n==0&&m==0)
      return 1;
      if(n<0||m<0)
      return 0;
      if(obstacleGrid[n][m]==1)
      return 0;
      if(dp[n][m]!=0)
      return dp[n][m];
      int up=paths(n-1,m,obstacleGrid);
      int left=paths(n,m-1,obstacleGrid);
      return dp[n][m]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
      if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1||obstacleGrid[0][0]==1)
      return 0;
      int ans=paths(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid);
      return ans;
    }
};