#include<climits>
int f(vector<int>& a,int i,int j){
    if(i>j) return 0;
    int maxi=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost = a[i-1]*a[k]*a[j+1] + f(a,i,k-1) + f(a,k+1,j);
        maxi=max(maxi,cost);
    }
    return maxi;
}
int maxCoins(vector<int>& a){
	// Write your code here.
    int n=a.size();
    a.insert(a.begin(),1);
    a.emplace_back(1);
    
    return f(a,1,n);
}
