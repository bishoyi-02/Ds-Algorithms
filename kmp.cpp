vector<int> kmp(string &s){
    int n=s.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;++i){
        int prev_idx=lps[i-1];
        while(prev_idx>0 && s[prev_idx]!=s[i]){
            prev_idx=lps[prev_idx-1];
        }
        lps[i]=prev_idx+(s[prev_idx]==s[i]?1:0);
    }
    return lps;
}