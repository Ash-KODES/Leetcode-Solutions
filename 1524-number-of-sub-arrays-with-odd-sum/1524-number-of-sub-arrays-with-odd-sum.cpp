class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        long long int even=0;
        long long int odd=0;
        int ans[arr.size()];
        ans[0]=arr[0];
        if(arr[0]%2)
        odd++;
        else
        even++;
        for(int i=1;i<arr.size();i++)
        {
            ans[i]=ans[i-1]+arr[i];
            if(ans[i]%2)odd++;
            else even++;
        }
        even++;
        int mod=(1e9+7);
        long long int x=(even%mod*odd%mod)%mod;
        return x;
        
        
    }
};