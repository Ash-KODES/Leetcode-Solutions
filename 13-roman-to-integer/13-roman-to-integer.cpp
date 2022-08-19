class Solution {
public:
    int romanToInt(string s) 
    {
        // hashing->map
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0;
        if(s.size()==1)
        return mp[s[0]];
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size()&&mp[s[i+1]]>mp[s[i]])
            {
                ans+=(mp[s[i+1]]-mp[s[i]]);
                i++;
            }
            else
            {
                ans+=mp[s[i]];
            }
        }
        return ans;
        
    }
};