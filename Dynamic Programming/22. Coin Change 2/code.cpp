int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<int>prev(x+1,0),curr(x+1,0);
    // Write your code here.  n
    for(int t=0;t<=x;t++){
        if(t%num[0]==0) prev[t]=t/num[0];
        else prev[t]=1e9;
    }
    
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int noTake= 0 + prev[target];
            int take = 1e9;
            if(num[ind]<=target) take=1+curr[target-num[ind]];
            curr[target]=min(take,noTake);
        }
        prev=curr;
    }
    return prev[x]>=1e9?-1:prev[x];
}
