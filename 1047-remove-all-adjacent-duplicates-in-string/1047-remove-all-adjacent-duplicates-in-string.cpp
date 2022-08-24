class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        for(auto val:s)
        {
            if(st.empty()==0)
            {
                if(st.top()==val)
                st.pop();
                else
                st.push(val);
            }
            else
            st.push(val);
        }
        string ans="";
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;  
    }
};
