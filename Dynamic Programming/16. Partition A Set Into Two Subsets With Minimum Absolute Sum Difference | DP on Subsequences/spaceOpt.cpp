int minSubsetSumDifference(vector<int>& arr, int n){
	// Write your code here.
    int sum=accumulate(arr.begin(), arr.end(), 0);
    vector<bool>prev(sum+1, false), curr(sum+1,false);
    
    prev[0] = curr[0] = true;
    if(arr[0]<=sum) prev[arr[0]]=true;
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=sum;target++){
            bool notTake=prev[target];
            bool take{false};
            if(arr[i]<=target) take=prev[target-arr[i]];
            curr[target]=take|notTake;
        }
        prev=curr;
    }
    
    int mini{INT_MAX};
    for(int i=0;i<=sum/2;i++){
        if(prev[i]){
            int s2=sum-i;
            mini=min(mini,abs(i-s2));
        }
    }
    return mini;
}
