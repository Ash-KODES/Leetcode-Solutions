class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
      unordered_map<int,int> mp;
      vector<int> temp;
      for(int i=0;i<nums.size();i++)
      {
        if(mp.find(target-nums[i])!=mp.end())
        {
          temp.push_back(i);
          temp.push_back(mp[target-nums[i]]);
          return temp;
        }
        mp.insert({nums[i],i});
      }
      return  temp;
    
    }
};