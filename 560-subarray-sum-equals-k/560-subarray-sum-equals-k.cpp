class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
       //Total number of subarray whose sum is k
       //Brute Froce-Finding All the subarray---adding their elements--checking if its equal to k or not.
       //O(n^3);
       //Optimal:precomputation
        map<int,int> mp;
        mp[0]++;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};