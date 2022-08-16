class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
      vector<int> v;
      int i=0;
      int j=0;
      if(m==0)
      {
        for(int i=0;i<n;i++)
        {
          nums1[i]=nums2[i];
        }
      }
      if(n==0)
      {
        return ;
      }
      while(i<m&&j<n)
      {
        if(nums1[i]<nums2[j])
        {
          v.push_back(nums1[i]);
          i++;
        }
        else
        {
          v.push_back(nums2[j]);
          j++;
        }
      }
      while(i<m)
      {
        v.push_back(nums1[i]);
        i++;
      }
      while(j<n)
      {
        v.push_back(nums2[j]);
        j++;
      }
      int ind=0;
      for(int ind=0;ind<n+m;ind++)
      nums1[ind]=v[ind];
    }
};