class Solution {
public:
    void helper(int index,vector<int>& ds,vector<vector<int>>& ans,vector<int>& nums)
    {
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index&&nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            helper(i+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        int index=0;
        helper(index,ds,ans,nums);
        return ans;
    }
};