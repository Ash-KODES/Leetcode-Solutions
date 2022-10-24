class Solution {
public:
    int helper(vector<string>& arr,int ind,string &s)
    {
      
      if(ind==arr.size())
      {
        set<char>check;
        for(auto val:s)
        check.insert(val);
        if(check.size()==s.size())
        return s.size();
        else
        return 0;
      }
      set<char>check;
      for(auto val:s)
      check.insert(val);
      if(check.size()!=s.size())
      return 0;
      s=s+arr[ind];
      int take=helper(arr,ind+1,s);
      int loop=arr[ind].size();
      while(loop--)
      {
        s.pop_back();
      }
      int not_take=helper(arr,ind+1,s);
      return max(take,not_take);
    }
    int maxLength(vector<string>& arr) 
    {
      string temp="";
      return helper(arr,0,temp);
    }
};