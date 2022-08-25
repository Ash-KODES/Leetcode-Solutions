class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        //BRUTE FORCE-o(n^3)
        //Optimal->sort then use two pointers
        //TC-nlogn+n^2
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            int lo=0;
            int hi=nums.size()-1;
            while(hi>lo)
            {
                if(hi==i)
                {
                    hi--;
                    continue;
                }
                if(lo==i)
                {
                    lo++;
                    continue;
                }
                int sum=nums[i]+nums[hi]+nums[lo];
                if(abs(sum-target)<diff)
                {
                    ans=sum;
                    diff=min(diff,abs(sum-target));
                }
                if(sum>target)
                hi--;
                else 
                lo++;
            }
        }
        return ans;
        
    }
};