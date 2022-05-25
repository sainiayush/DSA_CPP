int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    vector<int> prev(ls+1,0), curr(ls+1,0);
    int prime = 1e9+7;
    prev[0]=1;
    
    for(int i=1;i<=lt;i++){
        for(int j=ls;j>=1;j--){
            if(t[i-1]==s[j-1]) prev[j] = (prev[j-1] + prev[j])%prime;
            else prev[j]=prev[j];
        }
    }
    return prev[ls];
} 
