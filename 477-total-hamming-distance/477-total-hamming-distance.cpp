class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(100);
        for(auto i=0;i<nums.size();i++)
        {
          int pos=0;
          while(nums[i]>0)
          {
            v[pos]+=nums[i]&1;
            nums[i]/=2;
            pos++;
          }
        }
        int ans=0;
        for(auto val:v)
        {
          ans+=(nums.size()-val)*val;
        }
        return ans;
    }
};