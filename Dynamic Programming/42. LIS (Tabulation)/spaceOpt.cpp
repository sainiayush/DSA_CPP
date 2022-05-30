#include<vector>
#include<climits>
int longestIncreasingSubsequence(int arr[], int n){
    // Write Your Code here
    vector<int> dp(n,1);
    int maxi=1;
    
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(arr[ind]>arr[prev_ind]) dp[ind] = max(dp[ind], 1+dp[prev_ind]);
        }
        maxi=max(maxi,dp[ind]);
    }
    return maxi;
}
