int maximumProfit(vector<int> &prices, int n, int k){
    // Write your code here.
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int kTrans=1;kTrans<k+1;kTrans++){
                    if(buy) dp[ind][buy][kTrans] = max(-prices[ind]+dp[ind+1][0][kTrans], 
                                                      dp[ind+1][1][kTrans]);
                    else dp[ind][buy][kTrans] = max(prices[ind]+dp[ind+1][1][kTrans-1],
                                                   dp[ind+1][0][kTrans]);
                }
            }
        }
        return dp[0][1][k];
}
