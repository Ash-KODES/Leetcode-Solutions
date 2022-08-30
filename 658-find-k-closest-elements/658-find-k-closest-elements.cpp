class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<pair<int,int>> ans;
        vector<int> v;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back({abs(x-arr[i]),arr[i]});
        }
        //sort(ans.begin(),ans.end());
        //TC-o(nlogn)
        //-----------------------------------
        //heap--->maxheap
        priority_queue<pair<int,int>> pq;
        for(auto val:ans)
        {
            if(pq.size()==k)
            {
                if(val.first>=pq.top().first)
                continue;
                pq.pop();
                pq.push(val);
            }
            else
            pq.push(val);
        }
        while(pq.size()>0)
        {
            pair<int,int> p=pq.top();
            v.push_back(p.second);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};