class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
      stack<int> st;
      vector<int> v;
      //st.push_back()
      for(int i=nums2.size()-1;i>=0;i--)
      {
        if(st.empty())
        {
          v.push_back(-1);
        }
        else if(st.top()>nums2[i])
        {
          v.push_back(st.top());
        }
        else
        {
          while(!st.empty())
          {
            st.pop();
            if(st.size()==0)
            {
              v.push_back(-1);
              break;
            }
            if(st.top()>nums2[i])
            {
              v.push_back(st.top());
              break;
            }
          }
        }
        st.push(nums2[i]);
      }
      reverse(v.begin(),v.end());
      map<int,int> mp;
      for(int i=0;i<nums2.size();i++)
      {
        mp[nums2[i]]=v[i];
      }
      vector<int> ans;
      for(int i=0;i<nums1.size();i++)
        ans.push_back(mp[nums1[i]]);
      return ans;
      
    }
};