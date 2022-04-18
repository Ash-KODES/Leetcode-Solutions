class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> v;
        vector<int> original=nums;
        v.push_back(nums);
        next_permutation(nums.begin(),nums.end());
        while(nums!=original)
        {
            v.push_back(nums);
            next_permutation(nums.begin(),nums.end()); 
        }
        return v;
    }
};