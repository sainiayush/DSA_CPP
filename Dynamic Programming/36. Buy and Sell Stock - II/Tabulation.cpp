#include<vector>
long getMaximumProfit(long *values, int n){
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit  = max(-values[ind] + dp[ind+1][0], //bought
                              0 + dp[ind+1][1]); //not-bought;
            }else{
                profit = max(values[ind] + dp[ind+1][1], //sold
                             0 + dp[ind+1][0]); // not-sold
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
