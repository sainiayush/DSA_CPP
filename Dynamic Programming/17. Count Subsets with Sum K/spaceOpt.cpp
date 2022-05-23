int findWays(vector<int> &arr, int tar){
    // Write your code here.
    int n=arr.size();
    vector<int>prev(tar+1, 0), curr(tar+1, 0);
    prev[0] = curr[0] = 1;
    if(tar>=arr[0]) prev[arr[0]]=1;
    
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=tar;target++){
            int notPick=prev[target];
            int pick{};
            if(arr[ind]<=target) pick=prev[target-arr[ind]];
            curr[target]=pick+notPick;
        }
        prev=curr;
    }
    return prev[tar];
}
