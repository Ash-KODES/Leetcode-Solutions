class Solution {
public:
    int dp[3000][3000];
    int helper(vector<int>& nums,int ind,int prev_ind)
    {
        //BASE CASES
        if(ind==nums.size())
        return 0;
        if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
        int len=helper(nums,ind+1,prev_ind);
        if(prev_ind==-1||nums[prev_ind]<nums[ind])
        len=max(len,1+helper(nums,ind+1,ind));
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,-1);
    }
};