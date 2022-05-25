class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> v;
        for(auto val:nums)
        v.push_back(val);
        for(auto val:nums)
        v.push_back(val);
        stack<int> st;
        vector<int> temp;
        vector<int> ans;
        for(int i=2*nums.size()-1;i>=0;i--)
        {
            if(st.empty()==1)
            {
                temp.push_back(-1);
            }
            else if(st.empty()==0&&st.top()>v[i])
            {
                temp.push_back(st.top());
            }
            else if(st.empty()==0&&v[i]>=st.top())
            {
                while(!st.empty())
                {
                    int top=st.top();
                    if(top>v[i])
                    {
                        temp.push_back(top);
                        break;
                    }
                    st.pop();
                }
                if(st.empty()==1)
                temp.push_back(-1);
            }
            st.push(v[i]);
        }
        reverse(temp.begin(),temp.end());
        int size=nums.size();
        for(int i=0;i<size;i++)
        ans.push_back(temp[i]);
        return ans;
    }
    
};