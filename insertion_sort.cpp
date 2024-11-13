// take element place in its correct order

void insertion_sort(vector<int> &arr,int n){
    for(int i=0;i<n;++i){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

worst O(n^2), avg O(n^2), best O(n)