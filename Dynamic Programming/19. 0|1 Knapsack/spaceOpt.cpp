int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<int>prev(maxWeight+1, 0);
  
    for(int t=weight[0];t<=maxWeight;t++) prev[t]=value[0];
    
    
    for(int ind=1;ind<n;ind++){
        for(int w=maxWeight;w>=0;w--){
            int notTake= 0 + prev[w];
            int take=INT_MIN;
            if(weight[ind]<=w) take = value[ind]+prev[w-weight[ind]];
            prev[w]=max(notTake,take);
        }
    }
    return prev[maxWeight];
}
