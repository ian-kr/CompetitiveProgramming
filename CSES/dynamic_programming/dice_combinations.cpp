/**
 * @author: Ian Kristona
 * Date: 4/3/2025
 * Problem: Dice Combinations
 * Link: https://cses.fi/problemset/task/1633
 * 
 * LOGIC: 
 * Create a dp vector where dp[i] is equal to the number of ways to construct i
 * Base case: there is 1 way to construct 0
 * i repersents some number and j will be (1-6) where j will not be greater than i
 * Imagine you are creating a way to create i
 * j will be the first number you add to the construction of i 
 * Meaning that you need to add i-j to construction to construct i
 * If we know the numbe ways to consturct i-j we can add this dp[i]
 * And will take the MOD per question specifications.
 */


 #include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

 int main(void){

    ll n;
    cin >> n;

    vector<ll> dp(n+1);
    dp[0] = 1;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= 6 && (i-j) >= 0; j++){
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }


    cout << dp[n] << '\n';


    return 0;
 }