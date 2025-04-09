/**
 * @author: Ian Kristona
 * Date: 4/4/2025
 * Problem: Dice Combinations
 * Link: https://cses.fi/problemset/task/1634
 */

 #include <bits/stdc++.h>

 using namespace std;

 int main(void){

    int res = -1;

    int n,sum; cin >> n >> sum;
    vector<int> nums(n);
    for(auto& i: nums) cin >> i;
    sort(nums.begin(), nums.end());

    // dp[i][j] = number of coins to constuct i
    // if dp[i][j] is -1 then there is no ways to consturct i
    vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));

    // First columnum is 1 because there is only way to construct 0
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum && (nums[i-1]-j) >= 0; j++){
            if(dp[i-1][nums[i-1]-j] != -1){
                dp[i][j] = dp[i-1][nums[i-1]-j] + 1;
            }
            if(j == sum && dp[i][j] != -1){
                if(res == -1) res = dp[i][j];
                else res = min(res,dp[i][j]);
            }
        }
    }

    for(auto vec: dp){
        for(auto num: vec){
            cout << num << ' ';
        }
        cout << endl;
    }

    cout << res << endl;

    return 0;
 }
