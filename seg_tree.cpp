class Segtree{
public:
    int n;
    vector<int> t;
    
    Segtree(){}
    Segtree(int len){
        n=len;
        t.resize(4*n);
    }

    void build(int v,int tl,int tr, vector<int>&a){
        if(tl==tr){
            t[v]=a[tl];
            return;
        }
        int mid=(tl+tr)>>1;
        build(2*v,tl,mid,a);
        build(2*v+1,mid+1,tr,a);
        t[v]=t[2*v]+t[2*v+1];
    }

    int query(int v,int l,int r,int tl,int tr){
        if(tl>=l && r>=tr)
            return t[v];
        if(r<tl || tr<l)
            return 0;

        int mid=(tl+tr)>>1;
        int left=query(2*v,l,r,tl,mid);
        int right=query(2*v+1,l,r,mid+1,tr);
        return left+right;
    }

    void update(int v,int tl,int tr,int id,int val){
        if(tl==id && tr==id){
            t[v]=val;
            return;
        }
        if(id<tl || tr<id)
            return;

        int mid=(tl+tr)>>1;
        update(2*v,tl,mid,id,val);
        update(2*v+1,mid+1,tr,id,val);
        t[v]=t[2*v]+t[2*v+1];
    }

    void build(vector<int> &a){
        build(1,0,n-1,a);
    }

    int query(int l,int r){
        return query(1,l,r,0,n-1);
    }
    
    void update(int id,int val){
        update(1,0,n-1,id,val);
    }
};

