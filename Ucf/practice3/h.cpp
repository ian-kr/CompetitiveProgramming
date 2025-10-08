#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cin >> n;
    int largest = 0;
    while(n--){
        string s;
        cin >> s;
        int bits = 0;
        for(auto c :s)
            if(c != '.') bits++;
        largest = max(largest,32-bits);
    }

    if(largest == 0){
        cout << 32 << endl;
        return 0;
    }
    cout << largest << endl;


    return 0;
}