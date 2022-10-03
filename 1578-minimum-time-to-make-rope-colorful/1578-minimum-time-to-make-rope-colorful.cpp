class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
      int c=colors[0];
      int mini=neededTime[0];
      int ans=0;
      int flag=0;
      for(int i=0;i<colors.size();i++)
      {
        if(c==colors[i])
        {
          mini=max(mini,neededTime[i]);
        }
        else
        {
          ans+=mini;
          if(i+1==colors.size())
          {
            ans+=neededTime[i];
            flag++;
            break;
          }
          c=colors[i];
          mini=neededTime[i];
        }
      }
      if(flag==0)
      ans+=mini;
      int total=0;
      for(auto val:neededTime)
      total+=val;
      cout<<ans<<endl;
      return total-ans;
      
        
    }
};