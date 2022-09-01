class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s2.size()<s1.size())return 0;
        map<char,int> freq;
        for(int i=0;i<s1.size();i++)
        {
            freq[s1[i]]++;
        }
        map<char,int> check;
        int j=0;
        for(int i=0;i<s2.size();i++)
        {
            check[s2[i]]++;
            if(i-j+1==s1.size())
            {
                if(check==freq)
                return true;
                check[s2[j]]--;
                if(check[s2[j]]==0)check.erase(s2[j]);
                j++;
            }
        }
        return false;
    
    }
};