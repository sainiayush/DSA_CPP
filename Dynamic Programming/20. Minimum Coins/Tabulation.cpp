int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>>dp(n, vector<int>(x+1, -1));
    // Write your code here.  n
    for(int t=0;t<=x;t++){
        if(t%num[0]==0) dp[0][t]=t/num[0];
        else dp[0][t]=1e9;
    }
    
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int noTake= 0 + dp[ind-1][target];
            int take = 1e9;
            if(num[ind]<=target) take=1+dp[ind][target-num[ind]];
            dp[ind][target]=min(take,noTake);
        }
    }
    return dp[n-1][x]>=1e9?-1:dp[n-1][x];
}
