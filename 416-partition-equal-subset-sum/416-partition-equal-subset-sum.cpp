class Solution {
public:
    int dp[201][20001];
    bool helper(vector<int>& nums,int index,int sum)
    {
        //BASE CASES
        if(sum==0)
        return true;
        if(index==nums.size()-1)
        return sum==nums[index];
        if(dp[index][sum]!=-1)return dp[index][sum];
        bool pick=false;
        if(sum>=nums[index])
        pick=helper(nums,index+1,sum-nums[index]);
        bool not_pick=helper(nums,index+1,sum);
        return dp[index][sum]=pick||not_pick;
    }
    bool canPartition(vector<int>& nums)
    {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto val:nums)sum+=val;
        if(sum%2)
        return false;
        else
        sum=sum/2;
        return helper(nums,0,sum);
    }
};