class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total=0;
        int index=0;
        int consume=0;
        for(int i=0;i<gas.size();i++)
        {
            consume+=gas[i]-cost[i];
            if(consume<0)
            {
                index=i+1;
                consume=0;
            }
            total+=gas[i]-cost[i];
        }
        return total<0 ? -1:index;
    }
};