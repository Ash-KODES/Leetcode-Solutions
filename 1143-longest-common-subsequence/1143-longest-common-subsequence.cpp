class Solution {
public:
    int lcs(int ind1,int ind2,string &s,string &t,vector<vector<int>>&dp)
    {
      if(ind1<0||ind2<0)
      return 0;
      if(dp[ind1][ind2]!=-1)
      return dp[ind1][ind2];
      if(s[ind1]==t[ind2])
      {
        return dp[ind1][ind2]=1+lcs(ind1-1,ind2-1,s,t,dp);
      }
      else
      {
        return dp[ind1][ind2]=max(lcs(ind1-1,ind2,s,t,dp),lcs(ind1,ind2-1,s,t,dp));
      }
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        int len=lcs(text1.size()-1,text2.size()-1,text1,text2,dp);
        return len;
    }
};