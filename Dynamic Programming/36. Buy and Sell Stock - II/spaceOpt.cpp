#include<vector>
long getMaximumProfit(long *values, int n){
    //Write your code here
    vector<long> prev(2,0), curr(2,0);
    prev[0] = prev[1] = 0;
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit  = max(-values[ind] + prev[0], //bought
                              0 + prev[1]); //not-bought;
            }else{
                profit = max(values[ind] + prev[1], //sold
                             0 + prev[0]); // not-sold
            }
            curr[buy]=profit;
        }
        prev=curr;
    }
    return prev[1];
}
