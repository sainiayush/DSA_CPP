bool isPalindrome(string&str, int start,int end){
    while(start<end) if(str[start++]!=str[end--]) return false;
    return true;
}
int f(int i,int n,string& str){
    if(i==n) return 0;
    int minCost=INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(str,i,j)){
            int cost = 1+f(j+1,n,str);
            minCost = min(minCost,cost);
        }
    }
    return minCost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    return f(0,n,str)-1;
}
