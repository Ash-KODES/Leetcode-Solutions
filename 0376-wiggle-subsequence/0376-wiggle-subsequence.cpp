class Solution {
public:
    //prev=-1-->neg
    //prev=1-->pos
    int helper(vector<int>& nums,int ind,int parity,int prev,vector<vector<vector<int>>>&dp)
    {
      if(ind==nums.size())
      return 0;
      if(dp[ind][prev+1][parity+1]!=-1)
      return dp[ind][prev+1][parity+1];
      int not_take=helper(nums,ind+1,parity,prev,dp);
      int take=0;
      if(prev!=-1&&(nums[ind]-nums[prev])*parity<0)
      take=1+helper(nums,ind+1,parity*-1,ind,dp);
      else if(prev==-1)
      {
        take=1+max(helper(nums,ind+1,1,ind,dp),helper(nums,ind+1,-1,ind,dp));
      }
      //cout<<take<<" "<<not_take<<endl;
      return dp[ind][prev+1][parity+1]=max(take,not_take);
    }
    int wiggleMaxLength(vector<int>& nums)
    {
      vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(3,-1)));
      //why +1=>if len 3 then checked only twice.
      int ans=helper(nums,0,0,-1,dp);
      cout<<ans<<endl;
      return ans; 
    }
};