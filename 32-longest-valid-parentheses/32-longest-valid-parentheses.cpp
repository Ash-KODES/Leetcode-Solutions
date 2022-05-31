class Solution {
public:
    int longestValidParentheses(string s) 
    {
      stack<pair<char,int>> st;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]==')'&&st.size()>0&&st.top().first=='(')
        {
          st.pop();
        }
        else
        {
          st.push({s[i],i});
        }
      }
      vector<int> v;
      v.push_back(-1);
      while(!st.empty())
      {
        v.push_back(st.top().second);
        st.pop();
      }
      v.push_back(s.size());
      sort(v.begin(),v.end());
      int ans=0;
      for(int i=1;i<v.size();i++)
      ans=max(ans,v[i]-v[i-1]-1);
      return ans;
    }
};