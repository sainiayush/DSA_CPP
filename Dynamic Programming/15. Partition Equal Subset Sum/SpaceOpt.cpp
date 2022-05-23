bool canPartition(vector<int> &arr, int n){
	// Write your code here.
    int s=accumulate(arr.begin(),arr.end(),0);
    if(s%2) return false;
    int k=s/2;
    vector<bool>prev(k+1,false), curr(k+1,false);
    prev[0] = curr[0] = true;
    prev[arr[0]]=true;
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake = prev[target];
            bool take{false};
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            curr[target]=take|notTake;
        }
        prev=curr;
    }
    return prev[k];
}
