/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: Increasing Array
 * Link: https://cses.fi/problemset/task/1094
 */

 #include <bits/stdc++.h>

 using namespace std;
 
 int main(void){
    
    long long res = 0;
    long long n; cin >> n;
    vector<long long> nums(n);
    for(auto& i: nums) cin >> i;

    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1]){
            res += nums[i]-nums[i+1];
            nums[i+1] = nums[i];
        }
    }
    cout << res << endl;
 }