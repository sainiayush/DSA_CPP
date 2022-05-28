int f(int ind,int* arr,int prev_ind,int n){
    if(ind==n) return 0;
    int len = f(ind+1,arr,prev_ind,n);
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])  len = max(len, 1+f(ind+1,arr,ind,n));
    return len;
}
int longestIncreasingSubsequence(int arr[], int n){
    // Write Your Code here
    return f(0,arr,-1,n);
}
