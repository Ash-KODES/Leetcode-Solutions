class Solution {
public:
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
{
  vector<int> pre;
  pre.push_back(0);
  for(int i=0;i<arr.size();i++)
  {
    pre.push_back(pre[i]^arr[i]);
  }
  vector<int> ans;
  for(auto val:queries)
  {
    int l=val[0];
    int r=val[1];
    ans.push_back(pre[l]^pre[r+1]);
  }
  return ans;
}
};