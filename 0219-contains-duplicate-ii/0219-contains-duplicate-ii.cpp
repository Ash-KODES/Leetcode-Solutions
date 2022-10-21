class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map<int,int> mp;
        for(int j=0;j<nums.size();j++)
        {
            if(mp.find(nums[j])!=mp.end()&&j-mp[nums[j]]<=k)
            return 1;
            mp[nums[j]]=j;
        }
        return 0;
    }
};