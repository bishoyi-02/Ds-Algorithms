//  necessary cond'n  0<=l<=i<=r<s.len()

vector<int> z_algo(string &s){
    int sz=s.size();
    vector<int> z(sz);
    int l=0,r=0;
    for(int i=1;i<sz;++i){
        if(i>r){
            l=r=i;
            while(r<sz && s[r]==s[r-l]){
                r++;
            }
            z[i]=r-l;
            r--;
        }else{
            int rel_idx=i-l;
            if(i+z[rel_idx]<=r){ // necessary cond'n
                z[i]=z[rel_idx];
            }else{ // can't bring {r} to left then bring {l} to right
                // try finding largest substr that matches prefix
                l=i;
                while(r<sz && s[r]==s[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}


// optimized {cp-algo}

vector<int> z_algo(string &s){
    int sz=s.size();
    vector<int>z(sz);
    int l=0,r=0;
    for(int i=1;i<sz;++i){
        if(i+z[i]<r){
            int rel_idx=i-l;
            z[i]=min(z[rel_idx],r-i);
        }
        while(i+z[i]<sz && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
