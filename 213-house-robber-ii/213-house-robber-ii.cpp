class Solution {
public:
    int dp[101];
    int helper(vector<int>& nums,int ind)
    {
        if(ind==0)
        return nums[ind];
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int take=helper(nums,ind-2)+nums[ind];
        int not_take=helper(nums,ind-1);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums)
    {
        //Since A circle is Formed,we can say that first and last wont come in solution together
        memset(dp,-1,sizeof(dp));
        vector<int> start;
        vector<int> end;
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums.size()-1)start.push_back(nums[i]);
            if(i!=0)end.push_back(nums[i]);
        }
        int ans1=helper(end,end.size()-1);
        memset(dp,-1,sizeof(dp));
        int ans2=helper(start,start.size()-1);
        return max(ans1,ans2);
    }
};