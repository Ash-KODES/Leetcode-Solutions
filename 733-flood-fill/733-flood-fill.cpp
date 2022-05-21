class Solution {
public:
  void dfs(vector<vector<int>>& image, int sr,int sc, int      newColor,int initialcolor)
  {
    if(sc>=image[0].size()||sr<0||sr>=image.size()||sc<0)
      return;
    if(image[sr][sc]!=initialcolor)
      return ;
    image[sr][sc]=newColor;
    dfs(image, sr-1,sc,newColor,initialcolor);
    dfs(image, sr,sc-1,newColor,initialcolor);
    dfs(image, sr,sc+1,newColor,initialcolor);
    dfs(image, sr+1,sc,newColor,initialcolor);
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr,     int sc, int newColor) 
  {
      int initialcolor=image[sr][sc];
      if(initialcolor!=newColor)
      dfs(image,sr,sc,newColor,initialcolor) ;
      return image;
  }
};