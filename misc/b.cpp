#include <bits/stdc++.h>

using namespace std;

int r,c,n;
cin >> r >> c >> n;

struct tower{
    int i;
    int j;
    int num;
}

vector<vector<pair<int,int>>> grid;
vector<tower> towers;



int main(void){

    cin  >> r >> c >> n;
    grid = vector<vector<pair<int,int>>>(r,vector<pair<int,int>>(c,pair<int,int>));
    towers = vector(n);

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        towers[i].num = i+1;
    }

    



    return 0;
}