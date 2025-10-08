/**
 * @author: Ian Kristona
 * Date: 10/7/2025
 * Problem: Apple Division
 * Link: https://cses.fi/problemset/task/1621
 */

#include <bits/stdc++.h>

using namespace std;

long long n;
vector< long long> nums;
vector<bool> used;
long long mainSum = 0;
long long res = -1;
set<long long> sums;

void bt(long long idx, long long sum1){
    // already checked
    if(sums.count(sum1)) return;
    sums.insert(sum1);
    long long diff = abs(sum1-(mainSum-sum1));
    if(res > diff){
        res=diff;
        return;
    }
    // No further changes can be made
    if(idx == n) return;
    for(int i = idx; i < n; i++){
        if(used[i]) continue;
        // add changes
        sum1+=nums[i];
        used[i] = true;
        bt(idx+1,sum1); // create branch
        sum1-=nums[i];
        used[i] = false;
    }
}

int main(void){

    cin >> n;
    nums =  vector< long long>(n,0);
    used = vector<bool>(n,false);
    for(auto& i: nums) {
        cin >> i;
        mainSum+=i;
    }
    res = mainSum;
    // Everything is 1
    if(mainSum == n){
        (mainSum%2==0)?cout<<0<<endl : cout <<1<<endl;
        return 0;
    }
    bt(0,0);
    cout << res << endl;
    return 0;
}