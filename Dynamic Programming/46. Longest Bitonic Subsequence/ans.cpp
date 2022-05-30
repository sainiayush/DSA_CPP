int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	
    vector<int>dp1(n), dp2(n);
    
    for(int i=0;i<n;i++){
        dp1[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && dp1[i]<1+dp1[j]) 
                dp1[i] = 1+dp1[j];
    }
    
    int maxi=1;
    
    for(int i=n-1;i>=0;i--){
        dp2[i]=1;
        for(int j=n-1;j>i;j--){
            if(arr[i] > arr[j] && dp2[i]<1+dp2[j]) 
                dp2[i] = 1+dp2[j];
        }
        maxi = max(maxi, dp1[i]+dp2[i]-1);
    }
    return maxi;
} 
