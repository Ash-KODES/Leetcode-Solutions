class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(auto val:nums)
        total+=val;
        int to_find=total-x;
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(sum==to_find)
            {
                if(ans>nums.size()-(i-j))
                ans=nums.size()-(i-j);
            }
            sum+=nums[i];
            while(j<i&&sum>to_find)
            {
                sum-=nums[j];
                j++;
            }
        }
        if(sum==to_find)
        {
            if(ans>j)
            ans=j;
        }
        if(ans!=INT_MAX)
        return ans;
        return -1;
    }
};