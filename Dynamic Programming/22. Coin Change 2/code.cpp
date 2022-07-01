class Solution {
public:
    int change(int amount, vector<int>& coins) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n=coins.size();
        //vector<vector<int>> dp(n, vector<int>(amount+1,0));
        vector<int>prev(amount+1,0), curr(amount+1,0);
        
        for(int i=0;i<=amount;++i){
                prev[i]=(i%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTake=prev[target];
                int take=(coins[ind]<=target)?curr[target-coins[ind]]:0;
                curr[target]=take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
