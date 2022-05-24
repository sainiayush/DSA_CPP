int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>curr(w+1,0);
    
    for(int i=weight[0];i<=w;i++) curr[i]=profit[0]*((int) i/weight[0]);
    
    for(int ind=1;ind<n;ind++){
        for(int wg=0;wg<=w;wg++){
            int notTake=0+curr[wg];
            int take = INT_MIN;
                if(weight[ind]<=wg) take=profit[ind]+curr[wg-weight[ind]];
            curr[wg]=max(notTake,take);
        }
    }
    return curr[w];
}
