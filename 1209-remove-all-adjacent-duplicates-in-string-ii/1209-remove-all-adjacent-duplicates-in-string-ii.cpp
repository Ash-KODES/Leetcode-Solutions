class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> st;
        // pair-<element,freqency>
        for(auto val:s)
        {
            if(st.empty()==0)
            {
                pair<char,int> p=st.top();
                if(p.first==val)
                {
                    st.pop();
                    if(p.second+1!=k)
                    {
                        st.push({val,p.second+1});
                    }
                }
                else
                {
                    st.push({val,1});
                }
            }
            else
            st.push({val,1});
        }
        string ans="";
        while(st.size()>0)
        {
            pair<char,int> p=st.top();
            st.pop();
            while(p.second>0)
            {
                ans+=p.first;
                p.second--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};