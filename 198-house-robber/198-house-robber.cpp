class Solution {
public:
    int maxrob(int index,vector<int>& nums,vector<int> &dp)
    {
      if(index==0)
      return nums[0];
      if(index<0)
      return 0;
      if(dp[index]!=-1)
      return dp[index];
      int not_take=maxrob(index-1,nums,dp);
      int take=maxrob(index-2,nums,dp)+nums[index];
      return dp[index]=max(take,not_take);
    }
    int rob(vector<int>& nums)
    {
       vector<int> dp(nums.size(),-1);
       int ans=maxrob(nums.size()-1,nums,dp);
       return ans;
    }
};