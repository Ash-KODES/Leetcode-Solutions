class Solution 
{
public:
    int search(vector<int>& nums, int target)
    {
        int high=nums.size()-1;
        int low=0;
        int mid;
        while(high-low>1)
        {
            mid=(high+low)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
                low=mid;
        }
        if(nums[low]==target)
            return low;
        if(nums[high]==target)
            return high;
        else
            return -1;
    }
};