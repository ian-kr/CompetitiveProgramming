/**
 * @author: Ian Kristona
 * Date: 4/1/2025
 * Problem: Two Sets
 * Link: https://cses.fi/problemset/task/1092
 */

// LETS THINK ABOUT PREFIX SUM 
// n = 7
// 1 2 3 4 5 6 7
// prefix sum arr: 1 3 6 10 15 21 28 36
// 1 2 4 7 = 14
// 3 5 6 = 14
// If the prefix sum is odd then creating 2 sets with the same sum is impossible
// The only way to make 2 sets equal to each other the sum of the set must be half of the prefix sum of n
// The equation for the prefix sum is n*(n+1)/2
// there exist a pattern
// The right most and leftmost element form pairs that sum up to n
// 1+6 = 7 set 1
// 2 + 5 = 7 set 2
// 3 + 4 = 7 set 1
// n will be added to the set with the smaller size, unless it is even
// set1 = {1,6,3,4}
// set2 = {2,5,7}
// Essentialy the insertion to either set1 and set2 swaps for every pair inserted

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

 int main(void){

    ll n; cin >> n;

    if((n*(n+1)/2 % 2) == 1){
        cout << "NO\n";
        return 0; 
    }


    vector<int> set1;
    vector<int> set2;

        // is even 
        if(n%2==0){
            for(int left = 1,right = n; left < right; left++, right--){
                if(left%2==0){
                    set1.push_back(left);
                    set1.push_back(right);
                }
                else{
                    set2.push_back(left);
                    set2.push_back(right);
                }
            }
        }
        // is odd 
        else {
            for(int left = 1,right = n-1; left < right; left++, right--){
                if(left%2==0){
                    set1.push_back(left);
                    set1.push_back(right);
                }
                else{
                    set2.push_back(left);
                    set2.push_back(right);
                }
            }
            if(set1.size() > set2.size()) set2.push_back(n);
            else set1.push_back(n);
        }
    cout << "YES\n";
    cout << set1.size() << '\n';
    for(auto i: set1) cout << i << ' ';
    cout << '\n';
    cout << set2.size() << '\n';
    for(auto i: set2) cout << i << ' ';
    cout << '\n';
    return 0;
 }
