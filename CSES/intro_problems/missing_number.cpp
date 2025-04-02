/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: missing number
 * Link: https://cses.fi/problemset/task/1083
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n; cin >> n;
    n--;
    vector<int> nums(n);
    for(auto& i : nums) cin >> i;
    sort(nums.begin(), nums.end());

    for(int i = 0, j=1; i < n+1; i++,j++){
        if(nums[i] != j) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}