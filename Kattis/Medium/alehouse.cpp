#include <bits/stdc++.h>

using namespace std;

bool custom_sort(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

// Method 1, brute force, probaly to slow
void solve(vector<pair<int,int>>& vec, int& n, int& k, int& bigN){

	int left = 0;
	int right = k;
	int res = 0;
	while(right <= bigN){
		// DEBUG
		//cout <<"Range: " << left << ' ' << right << endl;
		int temp = 0;
		// check each pair to see if its in range
		for(int i = 0; i < n; i++){
			if(vec[i].first >=  left && vec[i].first <= right){
				//cout << "Enter at: " << vec[i].first << endl;
				temp++;
			}
			else if(vec[i].second >= left && vec[i].second <= right){
				//cout << "leaving at: " << vec[i].second << endl;
				temp++;
			}
		}
		//shift the range
		right++;
		left++;
		res = max(temp,res);
	}
	cout << res << endl;
}

int main(void){

	cin.tie(0)->sync_with_stdio(0);

	int n,k;
	cin >> n >> k;

	int ans = 0;
	int bigN = 0;
	vector<pair<int,int>> vec(n);
	for(auto& p: vec) {cin >> p.first >> p.second;bigN = max(p.second,bigN);}

	solve(vec,n,k,bigN);
	

	return 0;
}
