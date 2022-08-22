class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        //return the index
        //peak- a[i-1]<a[i]>a[i+1]//condtion
        
        //Brute force
        //traversing whole array
        //tc-o(n)
        //sc-O(1);
        
        //No alteranate element are equal==defetely there would be peak
        //mid-->a[mid-1] > a[mid] < a[mid+1]  <<<<<a[size-1]>a[size]=-OO
        //concept of binary search
        if(nums.size()==1)
        return 0;
        int lo=0;
        int hi=nums.size()-1;
        while(hi-lo>1)
        {
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid+1])
            {
                hi=mid;
            }
            else
            lo=mid+1;
        }
        //lo hi
        int ans;
        if(lo!=0)
        {
            if(nums[lo]>nums[lo+1]&&nums[lo]>nums[lo-1])
            ans=lo+1;
        }
        else if(lo==0)
        {
            if(nums[lo]>nums[lo+1])
            ans=lo+1;
        }
        if(hi!=nums.size()-1)
        {
            if(nums[hi]>nums[hi+1]&&nums[hi]>nums[hi-1])
            ans=hi+1;
        }
        if(hi==nums.size()-1)
        {
            if(nums[hi]>nums[hi-1])
            ans=hi+1;
        }
        return ans-1;
    }
};