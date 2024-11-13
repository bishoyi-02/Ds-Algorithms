sort(edges.all()); // {wt,u,v} according to wt
int sum=0;

for(auto &it : edges){
    if(ds.findParent(it[1])!=ds.findParent(it[0])){
        ds.Union(it[0],it[1]);
        sum+=it[0]
    }
}
return sum;