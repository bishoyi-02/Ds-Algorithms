priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
minHeap.push({0,{0,-1}}); // {dis,{node,parent}}
vector<int> vis(n,0);
int sum=0;
vector<vector<int>> mstEdges;

while(!minHeap.empty()){
    auto it =minHeap.top();
    minHeap.pop();
    int dis=it.first,node=it.second.first,parent=it.second.second;
    if (parent !=-1)
        mstEdges.push_back({node,parent});
    if(vis[node])
        continue;
    vis[node]=1;
    sum+=dis;
    for (auto &it : adj[node]){
        int adjNode=it.first,edgeWt=it.second;
        if(!vis[adjNode])
            minHeap.push({edgeWt,{adjNode,node}});
    }
}a

return sum;