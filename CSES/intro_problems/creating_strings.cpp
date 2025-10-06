/*
* @Author: Ian Kristona
* Date: 10/7/25
* Problem: Creating Strings
* Link: https://cses.fi/problemset/result/14824362/
*/
#include <bits/stdc++.h>

using namespace std;


string s;
int res = 0;
int n;
vector<int> freq(26,0);
vector<string> strs;

// Backtracking implementation
void bt(int idx, string curr){
    // Reached last possible branch in this segment
    if(idx == n){
        res++;
        strs.push_back(curr);
        return;
    }
    for(int i = 0; i < 26; i++){
        if(freq[i]==0) continue;
        // add changes
        curr[idx] = (char)(i+'a');
        freq[i]--;
        bt(idx+1,curr); // create new branch
        freq[i]++; // remove changes
    }
}

int main(void){


    cin >> s;
    n = s.size();
    string temp = string(n,'a');
    for(auto c: s) freq[c-'a']++;
    bt(0,temp);
    
    cout << res << endl;
    for(auto str: strs) cout << str << endl;


    return 0;
}
