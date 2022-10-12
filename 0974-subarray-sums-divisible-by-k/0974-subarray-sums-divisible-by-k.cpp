class Solution
{
    public:
        int subarraysDivByK(vector<int> &nums, int k)
        {
            int sum = 0;
            int rem = 0;
            int ans = 0;
            map<int, int> mp;
            mp[0]++;
            for (auto val: nums)
            {
                sum += val;
                rem = sum % k;
                if (rem < 0)
                    rem += k;
                ans += mp[rem];
                mp[rem]++;
            }
            return ans;
        }
};