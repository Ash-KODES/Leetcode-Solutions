class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
      
      int count=0;
      for(auto val:points)
      {
        map<float,int> mp;
        for(auto p:points)
        {
          if(p[1]==val[1]&&p[0]==val[0])
          continue;
          float slope=(1.0*(p[1]-val[1]))/(p[0]-val[0]);
          mp[slope]++;
        }

        for(auto m:mp)
        count=max(m.second,count);
      }
      return count+1;        
    }
};