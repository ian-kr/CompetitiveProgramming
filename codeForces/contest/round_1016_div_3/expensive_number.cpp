#include <bits/stdc++.h>

using namespace std;

int main(void){

    int tt;
    cin >> tt; 
    while(tt--){
        string s;
        cin >> s; 
        if(s.size() == 1){
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        bool flag = false;
        for(int i = s.size()-1; i >= 0; i--){
            if(!flag){
                if(s[i] == '0') res++;
                else flag = true;
            }
            else{
                if(s[i] != '0') res++;
            }
        }
        cout << res << endl;
        
    }

    return 0;
}