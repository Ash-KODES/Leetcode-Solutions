class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int> mp1;
        for(auto val: nums)
        mp1[val]++;
        vector<pair<int,int>> v;
        for(auto val:mp1)
        {
            v.push_back({val.second,val.first});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=v.size()-1;;i--)
        {
            if(ans.size()==k)
            break;
            ans.push_back(v[i].second);  
        }
        return ans; 
    }
};