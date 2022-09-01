class Solution {
public:
    void powerset(vector<int> nums,int ind,vector<vector<int>>& ans,vector<int> v)
    {
        //base cases
        if(ind==nums.size())
        {
            ans.push_back(v);
            return ;
        }
        //take
        v.push_back(nums[ind]);
        powerset(nums,ind+1,ans,v);
        //not_take
        v.pop_back();
        powerset(nums,ind+1,ans,v);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        powerset(nums,0,ans,v);
        return ans;
    }
};