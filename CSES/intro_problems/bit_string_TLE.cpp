/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: Bit String
 * Link: https://cses.fi/problemset/task/1617
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long MOD = 10e9 + 7;

int main(void){

    ll res = 1;
    ll n; cin >> n;
    vector<ll> bit_string(n,0);

    for(int i = 0; i < n; i++){
        sort(bit_string.begin(),bit_string.end());
        bit_string[n-1-i] = 1;
        ll temp = 0;
        do{
            temp++;
            res = (res+(ll)1) % MOD;
        } while(next_permutation(bit_string.begin(),bit_string.end()));
        cout <<  "\n1's in string = " << i << " Permutations: " << temp << endl;
    }  

    cout << res << endl;


    return 0;
}