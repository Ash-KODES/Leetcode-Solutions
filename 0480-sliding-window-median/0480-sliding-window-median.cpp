#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int> a(n+1);
        for(int i=1;i<n+1;i++)
        a[i]=nums[i-1];
        vector<double> ans;
        pbds s;
        for(int i=1;i<n+1;i++)
        {
          s.insert({a[i],i});
          if(s.size()==k)
          {
            if(k%2==0)
            {
              double mid=0;
              mid+=(*s.find_by_order(k/2)).first;
              mid+=(*s.find_by_order(k/2-1)).first;
              mid=mid*1.0/2;
              //cout<<mid<<endl;
              ans.push_back(mid);
            }
            else
            {
              double mid=0;
              mid+=(*s.find_by_order(k/2)).first;
              //cout<<mid<<endl;
              ans.push_back(mid);
            }
            
          }
          if(s.size()==k)
          s.erase(s.find({a[i-k+1],i-k+1}));
        }
        return ans;
    }
};