class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
      map<string,vector<string>> mp;
      for(auto val:strs)
      {
        string temp=val;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(val);
      }
      vector<vector<string>> v;
      for(auto val:mp)
      {
        v.push_back(val.second);
      }
      return v;
        
    }
};