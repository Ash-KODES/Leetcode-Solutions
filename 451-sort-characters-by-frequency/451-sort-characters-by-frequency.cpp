class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>> vp;
        for(auto val:mp)
        {
            vp.push_back({val.second,val.first});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        string ans="";
        for(auto val:vp)
        {
            while(val.first>0)
            {
                ans+=val.second;
                val.first--;
            }
        }
        return ans;
    }
};