/**
 * @author: Ian Kristona
 * Date: 10/10/2025
 * Problem: Chessboard and Queens
 * Link: https://cses.fi/problemset/task/1755
 */


#include <bits/stdc++.h>

using namespace std;

int main(void){

    string s;
    set<char> keys;
    map<char,int> freq;
    bool oddflag = false;
    int odds = 0;

    cin >> s;
    if(s.size()%2==1) oddflag = true;
    for(auto c: s){
        freq[c]++;
        keys.insert(c);
    }

    string start = "";
    string end = "";
    string middle = "";

    for(auto key: keys){
        if(freq[key]%2==1){
            middle+= string(freq[key],key);
            odds++;
        }
        else{
            start+= string(freq[key]/2,key);
            end+= string(freq[key]/2,key);
        }
        if(odds > 0 && oddflag == false){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        if(odds > 1 && oddflag){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        
    }
    reverse(end.begin(),end.end());
    cout << start+middle+end << endl;
    return 0;
}