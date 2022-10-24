class Solution {
public:
    int helper(vector<int>& nums,int i,int j)
    {
      if(i==j)
      return nums[i];
      if(i>j)
      return 0;
      int low=nums[i]+min(helper(nums,i+2,j),helper(nums,i+1,j-1));
      int high=nums[j]+min(helper(nums,i+1,j-1),helper(nums,i,j-2));
      return max(high,low);
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
      //Removal game dp
      // if(nums.size()==1)
      // return 1;
      int i=0;
      int j=nums.size()-1;
      int sum=0;
      for(int k=0;k<j+1;k++)
      sum+=nums[k];
      int ans=helper(nums,i,j);
      return 2*ans>=sum;
    }
}; 