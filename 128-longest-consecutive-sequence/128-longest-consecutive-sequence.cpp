class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size()==0)
        return 0;
        unordered_set<int> st;
        for(auto val:nums)
        st.insert(val);
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int count=1;
                int curr=nums[i];
                while(st.find(curr+1)!=st.end())
                {
                    count++;
                    curr++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};