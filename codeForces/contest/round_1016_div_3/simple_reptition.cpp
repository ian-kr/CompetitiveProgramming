#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_prime(ll &x){
    for(ll i = 2; i*i <= x; i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(void){

    int tt;
    cin >> tt; 
    while(tt--){
        ll x,k;
        cin >> x >> k;
        if(x != 1 && k != 1) cout << "NO\n";
        else{
            string s = "";
            for(ll i = 0; i < k; i++) s+=to_string(x);
            ll num = stoll(s);
            if(num == 1) cout << "NO\n";
            else{
                if(is_prime(num)) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }


    return 0;
}