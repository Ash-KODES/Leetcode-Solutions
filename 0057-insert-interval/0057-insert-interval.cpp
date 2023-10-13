class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>>ans;
        int flag=0;
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(max(intervals[i][1],intervals[i+1][1]));
                intervals[i+1]=temp;
                if(i==intervals.size()-2)
                flag++;
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        if(!flag)
        ans.push_back(intervals[intervals.size()-1]);
        return ans;

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
            vector<vector<int>> ans;
            for(int i=0;i<intervals.size()-1;i++)
            {
                if(intervals[i][1]>=intervals[i+1][0])
                {
                    if(intervals[i][1]>=intervals[i+1][1])
                    {
                        intervals[i+1][0]=intervals[i][0];
                        intervals[i+1][1]=intervals[i][1];
                    }
                    else
                    {
                        intervals[i+1][0]=intervals[i][0];
                    }
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }
            ans.push_back(intervals[intervals.size()-1]);
           
            return ans;
    }
};