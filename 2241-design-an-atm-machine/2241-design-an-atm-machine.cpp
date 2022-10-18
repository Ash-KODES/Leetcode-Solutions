class ATM {
    vector<long long> coins;
    vector<int> value = {20,50,100,200,500};
public:
    ATM() {
        coins.resize(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++)
        {
            coins[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        vector<long long> curr = coins;
        for(int i=4;i>=0;i--)
        {
            if(coins[i])
            {
                long long x = 0;
                while(coins[i] && amount>=value[i])
                {
                    x = amount/value[i];
                    x = min(x,coins[i]);
                    amount -= x*value[i];
                    coins[i] -= x;
                }
                
                ans[i] = x;
            }
        }
        
        if(amount)
        {
            coins = curr;
            return {-1};
        }
       return ans;
    }
};