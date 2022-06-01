class Solution {
public:
    int maxArea(vector<int>& height) 
    {
      int f=0;
      int e=height.size()-1;
      int ans=0;
      while(f<e)
      {
        ans=max(ans,min(height[f],height[e])*(e-f));
        if(height[f]<height[e])
          f++;
        else
          e--;
      }
      return ans;
    }
};