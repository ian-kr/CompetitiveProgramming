#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> nums;
vector<bool> used;
long long res = -1;

void bt(int idx, int sum1){
    // We can check the difference at every branch
    long long sum2 = 0;
    for(int i = 0; i < n; i++){
        // add the "non used" can be assumed to be contained in sum2
        if(used[i]) continue;
        sum2+=nums[i];
    }
    (res!=-1) ? res = min(res,abs(sum1-sum2)) : res = abs(sum1-sum2);

    // No further changes can be made
    if(idx == n) return;

    for(int i = 0; i < n; i++){
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
    nums =  vector<long long>(n,0);
    used = vector<bool>(n,false);
    for(auto& i: nums) cin >> i;

    bt(0,0);

    cout << res << endl;





    return 0;
}