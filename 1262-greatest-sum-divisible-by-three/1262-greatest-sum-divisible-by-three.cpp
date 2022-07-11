class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
      vector<int> one;
      vector<int> two;
      int sum=0;
      for(auto val:nums)
      {
        sum+=val;
        if(val%3==2)
        two.push_back(val);
        if(val%3==1)
        one.push_back(val);
      }
      sort(two.begin(),two.end());
      sort(one.begin(),one.end());
      if(sum%3==1&&two.size()<2)
      sum-=one[0];
      else if(sum%3==1)
      sum-=min(one[0],two[0]+two[1]);
      else if(sum%3==2&&two.size()==0)
      {
        sum-=one[0]+one[1];
      }
      else if(sum%3==2&&one.size()<2)
      sum-=two[0];
      else if(sum%3==2)
      sum-=min(two[0],one[0]+one[1]);
      
      return sum;
        
    }
};