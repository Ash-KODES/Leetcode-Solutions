class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int x=-1;
        int y=-1;
        int z=-1;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]+nums[i+1]>nums[i+2])
            {
                x=nums[i];
                y=nums[i+1];
                z=nums[i+2];
            }
        }
        if(z==-1)
        return 0;
        else
        return x+y+z;
        
    }
};