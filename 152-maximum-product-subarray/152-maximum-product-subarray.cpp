class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,nums[i]);
        }
        int curmax=1;
        int curmin=1;
        for(int i=0;i<nums.size();i++)
        {
            int temp=curmax;
            curmax=max(max(temp*nums[i],curmin*nums[i]),nums[i]);
            curmin=min(min(temp*nums[i],curmin*nums[i]),nums[i]);
            ans=max(ans,curmax);
            //cout<<curmin<<" "<<curmax<<endl;
        }
        return ans;
    }
};