class Solution {
public:
    int minOperations(int n)
    {
      int a[n];
      int sum=0;
      for(int i=0;i<n;i++)
      {
        a[i]=2*i+1;
        sum+=a[i];
      }
      sum/=n;
      int diff=0;
      for(int i=0;i<n;i++)
      diff+=abs(a[i]-sum);
      return diff/2;
    }
};