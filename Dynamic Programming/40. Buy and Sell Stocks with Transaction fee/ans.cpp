int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    int aheadNotBuy, currNotBuy, aheadBuy, currBuy;
    aheadBuy = aheadNotBuy = 0;
    
    for(int ind=n-1;ind>=0;ind--){
        //sell
        currNotBuy = max(prices[ind] - fee + aheadBuy, aheadNotBuy);
        
        //buy
        currBuy = max(-prices[ind] + aheadNotBuy, aheadBuy);
        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}
