/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: Weird Algorithm
 * Link: https://cses.fi/problemset/task/1068
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){

    // input
    long long  n; cin >> n;
    cout << n;
    while(n != 1){
        if(n%2==0) n/=2;
        else n = (n*3) + 1;
        cout << ' ' << n;
    }

    cout << '\n';
    return  0;
}