class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //Brute Force
        //O(n*n);
        //optimal way:-
        //Hash string:key-sorted string value-string
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for(auto val:mp)
        {
            v.push_back(val.second);  
        }
        return v;
        //TC--O(strs.size())
        //SC--O(strs.size())
        
    }
};