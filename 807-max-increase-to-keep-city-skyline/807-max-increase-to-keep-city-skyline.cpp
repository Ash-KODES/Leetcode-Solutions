class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
      int count=0; 
      for(int i=0;i<grid.size();i++)
      {
        for(int j=0;j<grid[0].size();j++)
        {
          int max1=INT_MIN;
          int max2=INT_MIN;
          for(int k=0;k<grid[0].size();k++)
          {
            max1=max(max1,grid[i][k]);
          }
          for(int k=0;k<grid.size();k++)
          {
            max2=max(max2,grid[k][j]);
          }
          count+=min(max1,max2)-grid[i][j];
        }
      }
      return count;
        
    }
};