class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        //Brute Force
        //collect all point--distance--sort it--(0-k-1);
        //SC-o(n);
        //TC-O(nlogn)
        //---------------------------------------------
        //Optimal--Heap
        //size=k=size of k
        //Tc-O(nlogk)
        //SC-o(n);
        priority_queue<pair<int,pair<int,int>>>  v;//max Heap
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            //dis1>dist2
            //sqrt(x1^2+y1^2)>sqrt(x2^2+y2^2)
            //(x1^2+y1^2)>(x1^2+y1^2)
            int dist=x*x+y*y;
            if(v.size()==k)
            {
                //incoming--lessser dist
                if(dist<v.top().first)
                {
                    v.pop();
                    v.push({dist,{x,y}});  
                } 
            }
            else
            v.push({dist,{x,y}});
        }
        //cout<<v.size()<<endl;
        vector<vector<int>> ans;
        while(v.size()>0)
        {
            pair<int,pair<int,int>> val=v.top();
            v.pop();
            vector<int> temp;
            temp.push_back(val.second.first);
            temp.push_back(val.second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};