#include<algorithm>
int f(vector<int>& cuts,int i,int j){
    if(i>j) return 0;
    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost = cuts[j+1]-cuts[i-1] + f(cuts,i,ind-1) +
                   f(cuts,ind+1,j);
        mini = min(mini,cost);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
       cuts.emplace_back(n);
       cuts.insert(cuts.begin(), 0);
       sort(cuts.begin(),cuts.end());
    return f(cuts,1,c);
}
