class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int>mini(n);
      vector<int>maxi(n);
      int m=INT_MAX;
      for(int i=0;i<n;i++)
      {
        mini[i]=min(nums[i],m);
        m=min(m,nums[i]);
      }
      m=INT_MIN;
      for(int i=n-1;i>-1;i--)
      {
        maxi[i]=max(nums[i],m);
        m=max(m,nums[i]);
      }
      int flag=0;
      for(int i=0;i<n;i++)
      {
        if(nums[i]>mini[i]&&nums[i]<maxi[i])
        flag++;
      }
      return flag;
    }
};