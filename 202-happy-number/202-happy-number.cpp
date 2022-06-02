class Solution {
public:
    int square(int n)
    {
      vector<int> v;
      while(n>0)
      {
        v.push_back(n%10);
        n/=10;
      }
      int ans=0;
      for(auto val:v)
      {
        ans+=val*val;
      }
      return ans;
    }
    bool isHappy(int n) 
    {
      map<int,int>mp;
      while(n!=1)
      {
        if(n==1)
          break;
        if(mp.find(n)!=mp.end())
          return 0;
        mp[n]++;
        n=square(n);
      }
      return true;
    }
};