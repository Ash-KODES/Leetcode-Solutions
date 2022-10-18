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
//***************************************************************************************************************
ll power(ll n, ll k, ll m = mod) { if(k == 0)return 1; if(k % 2)return (n * power(n, k - 1, m)) % m; return power((n * n) % m, k / 2, m); }
ll modinv(ll x, ll m = mod) { return power(x, m - 2); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (((a * b) % mod) * modinv(gcd(a, b))) % mod; }
//***************************************************************************************************************
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    string helper(int n)
    {
      if(n==1)
      return "1";
      string s=helper(n-1);
      vector<pair<char,char>> vp;
      int count=1;
      cout<<s<<endl;
      for(auto i=1;i<s.size();i++)
      {
          if(s[i]!=s[i-1])
          {
            vp.pb({count+'0',s[i-1]});
            count=1;
          }
          else
          count++;
      }
      string ans="";
      vp.pb({count+'0',s[s.size()-1]});
      for(auto val:vp)
      {
        //cout<<val.f<<" "<<val.ss<<endl;
        ans.pb(val.first);
        ans.pb(val.second);
      }
      return ans;
    }
    string countAndSay(int n) 
    {
        return helper(n);
    }
};