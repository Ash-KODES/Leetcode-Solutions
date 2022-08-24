class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        map<string,int> mp;
        for(auto val:strs)
        {
            string temp="";
            for(int i=0;i<val.size();i++)
            {
                temp+=val[i];
                mp[temp]++;
            }
        }
        string ans="";
        for(auto val:mp)
        {
            if(val.second<strs.size())
            continue;
            if(ans.size()<val.first.size())
            ans=val.first;
        }
        return ans;
        
    }
};