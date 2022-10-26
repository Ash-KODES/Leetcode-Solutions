class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[i-nums[i]]++;
        }
        long long int count=0;
        for(auto val:mp)
        {
            count+=(nums.size()-val.second)*val.second;
        }
        cout<<count<<endl;
        return count/2;
    }
};