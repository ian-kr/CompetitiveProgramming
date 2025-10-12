#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<string> graph;
vector<vector<bool>> seen;
int rooms = 0;

vector<int> dirx = {0,0,-1,1};
vector<int> diry = {-1,1,0,0};

void dfs(int r, int c){
    if(graph[r][c] == '#' || seen[r][c]) return;
    for(int i = 0; i < 4; i++){
        int ni = r + dirx[i];
        int nj = c + diry[i];
        cout << ni << nj << endl;
        if(ni < 0 || ni >= r || nj < 0 || nj >= c) return;
        seen[ni][nj] = true;
        cout << ni << nj << endl;
        dfs(ni,nj);
    }
}


int main(void){

    cin >> n >> m;
    graph = vector<string>(n);
    seen = vector<vector<bool>>(n,vector<bool>(m,false));
    for(auto& i : graph) cin >> i;

    for(int j = 0; j < n; j++){
        for(int i = 0; i < m ; i++){
            if(graph[j][i] == '.' && seen[j][i] == false){
                rooms++;
                dfs(j,i);
                seen[j][i] = true;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}