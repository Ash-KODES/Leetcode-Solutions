class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        //Brute Force:
        //o(n^2);
        //-------------------------------
        int prefix[nums.size()];
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        if(prefix[nums.size()-1]-nums[0]==0)
        return 0;
        int pviot=-1;
        for(int i=1;i<nums.size()-1;i++)
        {
            int left=0;
            left=prefix[i-1];
            int right=0;
            right=prefix[nums.size()-1]-prefix[i];
            if(left==right)
            {
                pviot=i;
                break;
            }
        }
        if(pviot==-1)
        {
            if(nums.size()>1&&prefix[nums.size()-2]==0)
            return nums.size()-1;
        }
        if(pviot)
        return pviot;
        else
        return -1;
    }
};