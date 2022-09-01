class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        //brute Force
        //o(n*k)
        //-----------------------------------------------
        //Optimal Approach->dequeue
        //-->pop-Back
        deque<int> dq;
        vector<int> ans;
        int j=0;//hi
        int i=0;//lo
        for(j=0;j<nums.size();j++)
        {
            while(!dq.empty()&&dq.back()<nums[j])
            dq.pop_back();
            dq.push_back(nums[j]);
            if(j-i+1==k)
            {
                ans.push_back(dq.front());
                if(dq.front()==nums[i])
                dq.pop_front();
                i++;
            }
        }
        return ans;
    }
};