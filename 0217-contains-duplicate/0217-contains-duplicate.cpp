class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // brute-map,sort
        // why map,use set dude !
        set<int> st;
        for(auto val:nums)
        st.insert(val);
        return !(st.size()==nums.size());
    }
};