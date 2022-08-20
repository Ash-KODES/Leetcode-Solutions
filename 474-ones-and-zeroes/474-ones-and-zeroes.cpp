class Solution {
public:
    int dp[610][110][110];
    int count_zero(string s)
    {
        int count=0;
        for(auto val:s)
        {
            count+=(val=='0');
        }
        return count;
    }
    int count_one(string s)
    {
        int count=0;
        for(auto val:s)
        {
            count+=(val=='1');
        }
        return count;
    }
    bool cantake(string s,int m,int n)
    {
        int one=count_one(s);
        int zero=count_zero(s);
        if(one<=n&&zero<=m)
        return 1;
        else
        return 0;
    }
    int helper(vector<string>& strs, int m, int n,int index)
    {
        if(index==0)
        {
            if(cantake(strs[index],m,n))
            return 1;
            else
            return 0;
        }
        if(dp[index][m][n]!=-1)
        return dp[index][m][n];
        int nottake=0+helper(strs,m,n,index-1);
        int take=INT_MIN;
        if(cantake(strs[index],m,n))
        {
            take=1+helper(strs,m-count_zero(strs[index]),n-count_one(strs[index]),index-1);
        }
        return dp[index][m][n]=max(take,nottake);
      
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(strs,m,n,strs.size()-1); 
    }
};