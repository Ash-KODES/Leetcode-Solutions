class Solution {
public:
    void sum(vector<int>& candidates, int target,int ind,vector<int> &val,vector<vector<int>> &hash)
    {
      if(target==0)
      {
        hash.push_back(val);
        return ;
      }
      if(ind==-1)
      {
        if(target==0)
        hash.push_back(val);
        return ;
      }
      if(target>=candidates[ind])
      {
        val.push_back(candidates[ind]);
        sum(candidates,target-candidates[ind],ind ,val,hash);
        val.pop_back();
      }
      sum(candidates,target,ind-1,val,hash);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
      vector<vector<int>> hash;
      int ind=candidates.size()-1;
      vector<int> val;
      sum(candidates,target,ind,val,hash);
      return hash;
    }
};