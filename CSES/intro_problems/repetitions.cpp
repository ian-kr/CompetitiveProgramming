/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: Repetitions
 * Link: https://cses.fi/problemset/task/1069
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){

    string s;
    cin >> s;
    int res = 0;
    int temp_res = 0;
    char curr = s[0];
    for(int i = 0; i < s.size(); i++){
        if(s[i] == curr) temp_res++;
        if(s[i] != curr) {
            res = max(temp_res,res);
            curr = s[i];
            temp_res = 1;
        }
        res = max(temp_res,res);
    }

    cout << res << '\n';   

    return 0;
}