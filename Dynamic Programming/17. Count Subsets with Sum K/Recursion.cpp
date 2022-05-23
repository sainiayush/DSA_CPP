int f(int ind,vector<int>& num,int tar){
    if(tar==0) return 1;
    if(ind==0) return tar==num[0];
    int notPick = f(ind-1,num,tar);
    int pick = 0;
    if(num[ind]<=tar) pick=f(ind-1,num,tar-num[ind]);
    return pick+notPick;
}
int findWays(vector<int> &num, int tar){
    // Write your code here.
    return f(num.size()-1,num,tar);
}
