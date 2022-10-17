class Solution {
public:
    bool checkIfPangram(string sentence)
    {
      set<int> st;
      for(auto val:sentence)
      st.insert(val);
      return st.size()==26;  
    }
};