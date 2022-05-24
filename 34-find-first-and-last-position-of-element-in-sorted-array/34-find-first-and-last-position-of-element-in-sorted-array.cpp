class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
      int loc1=INT_MAX;
      int loc2=INT_MIN;
      int low=0;
      int high=nums.size()-1;
      int mid;
      if(nums.size()==0)
      {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        return  ans;
      }
      while(high-low>1)
      {
        mid=(high+low)/2;
        if(nums[mid]==target)
        {
          loc1=mid;
          high=mid-1;
          continue;
        }
        if(nums[mid]>target)
          high=mid-1;
        else
          low=mid;
      }
      if(nums[high]==target&&high<loc1)
        loc1=high;
      if(nums[low]==target&&low<loc1)
        loc1=low;
      low=0;
      high=nums.size()-1;
      while(high-low>1)
      {
        mid=(high+low)/2;
        if(nums[mid]==target)
        {
          loc2=mid;
          low=mid+1;
          continue;
        }
        if(nums[mid]>target)
          high=mid-1;
        else
          low=mid;
      }
      if(nums[high]==target&&high>loc2)
        loc2=high;
      if(nums[low]==target&&low>loc2)
        loc2=low;
      
      vector<int> ans;
      if(loc1==INT_MAX)
      {
        ans.push_back(-1);
        ans.push_back(-1);
      }
      else
      {
        ans.push_back(loc1);
        ans.push_back(loc2);
      }
      return ans;
    }
};