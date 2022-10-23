class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
      vector<int> ans;
      map<int,int>mp;
      int sum=0;
      for(auto val:nums)
      {
        mp[val]++;
        if(mp[val]==2)
        {
          ans.push_back(val);
          sum-=val;
        }
        sum+=val;
      }
      ans.push_back(nums.size()*(nums.size()+1)/2-sum);
      return ans;
        
    }
};