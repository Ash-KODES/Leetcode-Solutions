class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)     {
        int even=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            even+=nums[i];
        }
        vector<int> ans;
        for(auto val:queries)
        {
            if(nums[val[1]]%2==0)
            {
                if((val[0])%2==0)
                {
                    even+=(val[0]);
                }
                else
                {
                    even-=(nums[val[1]]);
                }
            }
            else
            {
                if((val[0])%2)
                {
                    even+=(val[0]+nums[val[1]]);
                }
            }
            nums[val[1]]+=val[0];
            ans.push_back(even);
        }
        return ans;
    }
};