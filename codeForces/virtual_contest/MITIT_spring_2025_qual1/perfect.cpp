#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main(void){


    int tt;
    cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        for(ll i = 45;i; i++){
            string s = to_string(i*i);
            cout << s << endl;
            if(s.size() == n && s.find("2025") != string::npos){
                cout << s << endl;
                break;
            }
            if(s.size() > 1000){cout << "impossble\n";break;}
        }
    }

    return 0;
}