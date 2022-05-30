int findNumberOfLIS(vector<int> &arr){
    // Write your code here.
    int n=arr.size();
    vector<int>dp(n), cnt(n);
    int maxi=1;
    
    for(int i=0;i<n;i++){
        dp[i]=1; cnt[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && 1+dp[j]>dp[i]) dp[i]=1+dp[j], cnt[i]=cnt[j];
            else if(arr[i]>arr[j] and 1+dp[j]==dp[i]) cnt[i]+=cnt[j];
        }
        maxi=max(maxi,dp[i]);
    }
    
    int nos{};
    for(int i=0;i<n;i++) if(maxi==dp[i]) nos+=cnt[i];
    
    return nos;
}
