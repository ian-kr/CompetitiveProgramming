#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 +7;

int main(void){
    
    
    ll n,x,res = 0;
    cin >> n >> x;
    vector<ll>nums(n);
    for(auto& i: nums) cin >> i;
    // dp[i][j] being the number of ways to construct x
    vector<vector<ll>> dp(n+1, vector<ll>(x+1,0));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= x && i-j > 0; j++){
            dp[i][j] = (dp[i][j]%MOD+dp[i-1][nums[i-1]-j]%MOD)%MOD;
        }
    }
    
    for(int i = 0; i <= n; i++){
        res = ((res%MOD)+dp[i][x]%MOD)%MOD;
    }

    for(auto v: dp){
        for(auto i: v){
            cout << i << ' ';
        }
        cout << endl;
    }
    
    cout << res << endl;
    
    return 0;
}