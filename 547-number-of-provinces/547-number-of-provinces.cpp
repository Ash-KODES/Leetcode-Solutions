class Solution {
public:
    void DFS(vector<vector<int>>& isConnected,vector<int>& vis,int row)
    {
        vis[row]=1;
        for(int i=0;i<isConnected[row].size();i++)
        {
            if(i==row)
            continue;
            if(vis[i]==0&&isConnected[row][i]==1)
            DFS(isConnected,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int row=isConnected.size();
        vector<int> vis(row,0);
        int count_province=0;
        int count=0;
        for(int i=0;i<row;i++)
        {
            if(vis[i]==0)
            {
                DFS(isConnected,vis,i);
                count++;
            }
        } 
        return count;
    }
};