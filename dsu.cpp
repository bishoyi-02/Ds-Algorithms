class DisjointSet{
    private:
        vector<int> parent,size;

    public:
    DisjointSet(int n){
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;++i)parent[i]=i;
    }

    void unionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
    
    int findUParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUParent(parent[node]);
    }

};