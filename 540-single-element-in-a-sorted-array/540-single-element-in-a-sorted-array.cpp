class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        //O(n)
        // int xor_result=0;
        // for(int i=0;i<nums.size();i++)
        // xor_result^=nums[i];
        // return xor_result;
        //Optimal
        //--------------------------------
        if(nums.size()==1)
        return nums[0];
        if(nums[0]!=nums[1])
        return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2])
        return nums[nums.size()-1];
        int hi=nums.size()-1;
        int lo=0;
        while(hi-lo>1)
        {
            int mid=(lo+hi)/2;
            // if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            // return nums[mid];
            if(((mid%2)==0&&nums[mid]==nums[mid+1])||((mid%2)==1&&nums[mid]==nums[mid-1]))
            lo=mid+1;
            else
            hi=mid;
        }
        if(nums[lo]!=nums[lo+1]&&nums[lo]!=nums[lo-1])
        return nums[lo];
        if(nums[hi]!=nums[hi-1]&&nums[hi]!=nums[hi+1])
        return nums[hi];
        return -1;
    }
};