class Solution {
public:
    int longestPalindrome(string s)
    {
        int ans=0;
        map<char,int> mp;
        for(auto val:s)
        {
            mp[val]++;
        }
        int flag=0;
        for(auto val:mp)
        {
            if(val.second%2)
            flag++;
            ans+=val.second/2;
            //cout<<val.second<<endl;
        }
        ans*=2;
        if(flag)
        ans++;
        return ans;
    }
};