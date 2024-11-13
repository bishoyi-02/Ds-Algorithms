//push max ele to last by adj swaps on each iteration

void bubble_sort(vector<int> &arr,int n){
    bool swapped=0;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=1;
            }
        }
        if(!swapped)
            break;
    }
}

// best O(n), worst O(n^2) , avg O(n^2)
