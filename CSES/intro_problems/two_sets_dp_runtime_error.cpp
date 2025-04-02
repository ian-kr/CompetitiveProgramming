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
// Now that we have a target sum we can use dp to create set1
// And if we know set1 we know set2

// This results in a run time error because prefix sum becomes to large and a vector can not allocate enough memory 

#include <bits/stdc++.h>

using namespace std;

 int main(void){

   long long n; cin >> n;
   long long prefix_sum = (n+1)*n/2;

   if(prefix_sum%2==1){
      cout << "NO\n";
      return 0;
   }
   cout << prefix_sum << endl;
   prefix_sum = prefix_sum/2;
   vector<vector<bool>> dp(n+1,vector<bool>(prefix_sum+1,true));
   cout << prefix_sum << endl;
   cout << "YES\n";
   pair<long long,long long> point;
   for(long long i = 1; i <= n; i++){
      for(long long j = 1; j <= prefix_sum; j++){
         // First row is special case
         if(i == 1){
            if(i != j) dp[i][j] = false;
            continue;
         }
         // Must prove it is false
         long long diff = j-i;
         if(diff < 0) dp[i][j] = false;
         else{
            // go back to see if its impossible to contruct the difference
            if(dp[i-1][diff] == false) dp[i][j] = false;
         }
         if(j == prefix_sum && dp[i][j]) point = {i,j};
      }
   }

   set<long long> set1;
   set<long long> set2;
   for(long long i = 1; i <= n; i++) set2.insert(i);
   while(point.first > 0 && point.second > 0 && dp[point.first][point.second]){
   cout << point.first << ' ' << point.second << endl;
    set1.insert(point.first);
    set2.erase(point.first);
    point.second = point.second - point.first;
    point.first--;
   }

   cout << set1.size() << endl;
   for(auto n: set1) cout << n << ' ';
   cout << endl;

   cout << set2.size() << endl;
   for(auto n: set2) cout << n << ' ';
   cout << endl;

   
    return 0;
 }
