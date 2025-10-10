/**
 * @author: Ian Kristona
 * Date: 10/10/2025
 * Problem: Chessboard and Queens
 * Link: https://cses.fi/problemset/task/1624
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int res = 0;
vector<string> grid(8);
set<int> col,d1,d2;

// Backtracking method
void bt(int r){
    if(r == 8){
        res++;
        return;
    }
    for(int c = 0; c < 8; c++){
        if(grid[r][c] == '*' || col.count(c) || d1.count(r-c) || d2.count(r+c)){
           continue; 
        }
        //add changes
        d1.insert(r-c);
        d2.insert(r+c);
        col.insert(c);
        // create a new branch
        bt(r+1);
        //remove changes
        d1.erase(r-c);
        d2.erase(r+c);
        col.erase(c);
    }
}


int main(void){
    for(auto& i: grid) cin >> i;
    bt(0);
    cout << res << endl;
    return 0;
}