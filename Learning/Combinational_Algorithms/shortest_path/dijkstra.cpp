/*
*@Author: Ian Kristona
*Date: 11/18/2024
*Concept: Dijkstra's Algorithm
* From N0 to Nn-1
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> iPair;

class Graph{
    // Attributes
    int V; // Num of arcs/verticies
    list<pair<int,int>>* adj;

    public:
    // Constuctor
    Graph(int V);
    //Add edge to node in graph
    void addEdge(int n1, int n2, int d);
    // Find the shortest path
    void dijkstras(int start);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair>[V];
}
void Graph::addEdge(int n1, int n2, int d){
    adj[n1].push_back(make_pair(n2,d));
    adj[n2].push_back(make_pair(n1,d));
}
void Graph::dijkstras(int start){
    // Other lanagues should already have the correct sorting of pq such as python
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> cost(V,INF);
    pq.push(make_pair(0,start));
    cost[start] = 0;

    while(!pq.empty()){
        // First is distance, second is the node label
        int n1 = pq.top().second;
        pq.pop();
        list<pair<int,int>>::iterator i;
        for(i = adj[n1].begin(); i != adj[n1].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
    
            if(cost[v] > cost[n1] + weight){
                cost[v] = cost[n1] + weight;
                pq.push(make_pair(cost[v],v)); 
            }
        }
    }
    for(int i = 0 ; i < cost.size(); i++){
        cout << "Dist to Node " << i << " is " << cost[i] << endl;
    }
    cout << endl;
}

int main(){

    int V = 7;
    Graph g(V);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 10);
    g.addEdge(3, 5, 15);
    g.addEdge(4, 6, 2);
    g.addEdge(5, 6, 6);
    g.dijkstras(0);

    return 0;
}