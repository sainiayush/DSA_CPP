int f(int ind,vector<int>& price,int N){
    if(ind==0) return N*price[0];
    int notTake=0+f(ind-1,price,N);
    int take=INT_MIN;
    if((ind+1)<=N) take=price[ind]+f(ind,price,N-ind-1);
    return max(take,notTake);
}
int cutRod(vector<int> &price, int n){
	// Write your code here.
    return f(n-1,price,n);
}
