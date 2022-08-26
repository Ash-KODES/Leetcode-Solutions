class Solution {
public:
    //func(a,ind)
    //->whats the min number of coins required
    int dp[20][10001];
    long int helper(vector<int>& coins, int amount,int ind)
    {
        //BASE CASE
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            return amount/coins[ind];
            else
            return INT_MAX;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        long int not_take=helper(coins,amount,ind-1);
        long int take=INT_MAX;
        if(amount>=coins[ind])
        take=1+helper(coins,amount-coins[ind],ind);
        return dp[ind][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=helper(coins,amount,coins.size()-1);
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};