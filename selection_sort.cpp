//selcect min and swap with the ith element

void selection_sort(vector<int &arr,int n){
    for(int i=0;i<n-1;++i){
        mini=i;
        for(int j=i;j<n;++j){
            if(arr[mini]>arr[j])
                mini=j;
        }
        swap(arr[i],arr[mini]);
    }
}

// best,worst,avg O(n^2)