class Solution {
public:
    void dfs(int n,int m,vector<vector<char>>& grid)
    {
      if(n>=grid.size()||n<0||m>=grid[0].size()||m<0)
        return ;
      if(grid[n][m]!='1')
        return ;
      grid[n][m]='2';
      dfs(n-1,m,grid);
      dfs(n+1,m,grid);
      dfs(n,m-1,grid);
      dfs(n,m+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
      int count=0;
        for(auto i=0;i<grid.size();i++)
        {
          for(auto j=0;j<grid[i].size();j++)
          {
            if(grid[i][j]=='1')
            {
              dfs(i,j,grid);
              count++;
            }
          }
        }
      return count;
    }
};