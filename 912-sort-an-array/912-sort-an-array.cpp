class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        int freq[100001]={0};
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]+5*10000]++;
        }
        vector<int> ans;
        for(int i=0;i<1e5+1;i++)
        {
            while(freq[i]>0)
            {
                ans.push_back(i-5*10000);
                freq[i]--;
            }
        }        
        return ans;
        
    }
};