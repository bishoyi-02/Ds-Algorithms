vector<int>  dijkstra(int n, vector<vector<int>> adj[],int src){
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for(int i=0;i<n;++i)dist[i]=1e9;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            int edgeWt=it[1];
            int adjNode=it[0];
            if(dis+edgeWt<dist[adjNode]){
                dist[adjNode]=dis+edgeWt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}