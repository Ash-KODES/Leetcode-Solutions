class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
      int pos=nums.size()-1;
      for(int i=nums.size()-1;i>=0;i--)
      {
        if(i+nums[i]>=pos)
        pos=i;
      }
      return (pos==0);
      return false;
    }
};