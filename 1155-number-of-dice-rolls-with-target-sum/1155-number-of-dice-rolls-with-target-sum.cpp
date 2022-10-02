class Solution {
public:
    int dp[31][1001];
    int mod=1e9+7;
    int helper(int n,int k,int ind,int sum)
    {
      if(sum==0&&ind==n)
      return 1;
      if(ind==n||sum<0)
      return 0;
      if(dp[ind][sum]!=-1)
      return dp[ind][sum];
      int ans=0;
      for(int i=1;i<=k;i++)
      {
        ans=(ans%mod+helper(n,k,ind+1,sum-i)%mod)%mod;
      }
      return dp[ind][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
      memset(dp,-1,sizeof(dp));
      return helper(n,k,0,target);   
    }
};