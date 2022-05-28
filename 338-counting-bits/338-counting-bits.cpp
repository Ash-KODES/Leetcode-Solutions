class Solution {
public:
    vector<int> countBits(int n)
    {
      int a[n+1];
      for(int i=0;i<n+1;i++)
      {
        int count=0;
        int temp=i;
        while(temp>0)
        {
          count+=(temp&1);
          temp=(temp>>1);
        }
        a[i]=count;
      }
      vector<int> v;
      for(int i=0;i<n+1;i++)
      v.push_back(a[i]);
      return v;  
    }
};