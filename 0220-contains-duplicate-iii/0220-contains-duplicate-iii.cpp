/*Ashutosh Kumar Choudhary*/
#include <bits/stdc++.h>
using namespace std;
//***************************************************************************************************************
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//***************************************************************************************************************
#define ll long long
#define mod 1000000007
#define inf 1e18
#define pb push_back
#define intmax INT_MAX
#define intmin INT_MIN
#define f first
#define ss second
#define pi acos((long double)(-1))
#define all(x) (x).begin(), (x).end()
#define endl '\n'
//***************************************************************************************************************
ll power(ll n, ll k, ll m = mod) { if(k == 0)return 1; if(k % 2)return (n * power(n, k - 1, m)) % m; return power((n * n) % m, k / 2, m); }
ll modinv(ll x, ll m = mod) { return power(x, m - 2); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (((a * b) % mod) * modinv(gcd(a, b))) % mod; }
//***************************************************************************************************************
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
{
    ll n=nums.size();
    multiset<ll> st;
    bool check=false;
    st.insert(nums[0]);
    for(int i=1;i<n;i++)
    {
        
        auto it=st.lower_bound(nums[i]);
        // cout<<nums[i]<<" "<<*it<<endl;
        if(st.size()>0&&it!=st.begin())
        {
            auto temp=it;
            temp--;
            if(abs(*temp-nums[i])<=valueDiff)
            check=true;
        }
        if(it!=st.end()&&st.size()>0&&abs(*it-nums[i])<=valueDiff)
        {
            check=true;
        }
        if(st.size()==indexDiff)
        {
            st.erase(st.find(nums[i-indexDiff]));
        }
        st.insert(nums[i]);
        // cout<<check<<endl;
    
    }
    return check;
}
};





