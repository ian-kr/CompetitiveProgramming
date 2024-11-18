/**
 * Author: Ian Kristona
 * Date: 10/25/2024
 * Link: https://lmcodequestacademy.com/problem/around-and-around
 * Visual: https://excalidraw.com/#json=iLvX2ue4CGgG8eAlatHjb,d6pax69AQAdGPcmluC6koA
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){

    const double pi = 3.1415926;
    int test;
    cin >> test; 

    while(test--){
        double n; cin >> n;
        double r =6378.1343444;
        double dist = 2.0 * pi * (r+n);
        cout << setprecision(1);
        cout << dist << endl;
    
    }

    return 0;
}