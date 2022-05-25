class Solution {
public:
    int count=0;
    map<pair<int,int>,int> mp;
    void dfs(vector<vector<int>>& grid,int row,int column)
    {
      if(mp[{row,column}]>0)
      return ;
      if(row<0||column<0)
      {
        count++;
        return ;
      }
      if(row>=grid.size()||column>=grid[0].size())
      {
        count++;
        return ;
      }
      if(grid[row][column]==0)
      {
        count++;
        return;
      }
      mp[{row,column}]++;
      dfs(grid,row,column-1);
      dfs(grid,row,column+1);
      dfs(grid,row-1,column);
      dfs(grid,row+1,column);
      
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
      int flag=0;
      for(int i=0;i<grid.size();i++)
      {
        for(int j=0;j<grid[0].size();j++)
          if(grid[i][j]==1)
          {
            dfs(grid,i,j);
            flag++;
            break;
          }
        if(flag)
        break;
      }
      
      return count;
    }
};