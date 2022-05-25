int findLCSLen(string& str,string& ptr,int n,int m){
    vector<int> prev(m+1,0), curr(m+1,0);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i-1]==ptr[j-1]) curr[j]=1+prev[j-1];
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}
int canYouMake(string &str, string &ptr){
    // Write your code here.
    int n=str.size(), m=ptr.size();
    int lcs=findLCSLen(str,ptr,n,m);
    return (n+m-2*lcs);
}
