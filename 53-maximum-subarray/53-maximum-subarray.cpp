class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
      int sum=nums[0];
      int best=INT_MIN;
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]+sum>nums[i])
        sum+=nums[i];
        else 
        sum=nums[i];
        best=max(best,sum);
      }
      sort(nums.begin(),nums.end());
      int maxi=nums[nums.size()-1];
      return max(max(best,sum),maxi);
    }
     
};