class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //OPTIMAL-HEAP
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        vector<pair<int,int>> v;
        for(auto val:mp)
        {
            v.push_back({val.second,val.first});
        }
        priority_queue<pair<int,int>> pq;//heap--min heap
        for(auto val:v)
        {
            //max size--pq--k
            if(pq.size()==k)
            {
                if(-1*(pq.top().first)<val.first)
                {
                    pq.pop();
                    pq.push({-1*(val.first),val.second});
                }
            }
            else
            pq.push({-1*val.first,val.second});
        }
        vector<int> ans;
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};