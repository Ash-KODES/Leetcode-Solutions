class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(auto val:s)
        {
            if(val=='['||val=='{'||val=='(')
            st.push(val);
            else 
            {
                if(st.empty())
                return false;
                if(st.top()=='('&&val==')'||st.top()=='{'&&val=='}'||st.top()=='['&&val==']')
                {
                    st.pop();
                }
                else
                return false;
            }
        }
        return (st.empty());
        
    }
};