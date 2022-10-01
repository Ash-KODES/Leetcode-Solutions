class Solution {
public:
    int helper(string s,int ind,int dp[])
    {
      if(ind==s.size())
      return 1;
      if(s[ind]=='0')
      return 0;
      if(dp[ind]!=-1)
      return dp[ind];
      int one=helper(s,ind+1,dp);
      int two=0;
      int num=100;
      if(ind+1<s.size())
      num=(s[ind]-'0')*10+(s[ind+1]-'0');
      if(num<27&&num>9)
      two=helper(s,ind+2,dp);
      return dp[ind]=one+two;
    }
    int numDecodings(string s) 
    {
        int dp[10000];
        memset(dp,-1,sizeof(dp));
        return helper(s,0,dp);
    }
};