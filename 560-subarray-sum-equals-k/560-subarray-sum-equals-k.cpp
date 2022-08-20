class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
       map<int,int> mp;
       int sum=0;
       int ans=0;
       mp[sum]++;
       for(int i=0;i<nums.size();i++)
       {
          sum+=nums[i];
          if(mp.find(sum-k)!=mp.end())
          ans+=mp[sum-k];
          mp[sum]++;
       }
       return ans;
    }
};