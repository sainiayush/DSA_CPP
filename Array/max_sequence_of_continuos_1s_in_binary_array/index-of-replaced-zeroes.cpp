int findZeroes(int arr[], int n, int m) {
        int l=0;
        int count=0;
        int i=0, j=0, maxc=INT_MIN;
        
        while(i<n){
            if(count<=m){
                if(arr[i]==0){
                count++;
                }
                i++;
            }
            
            while(count>m){
                
                if(arr[j]==0){
                    count--;
                }
                j++;
            }
            
            if(maxc<i-j && count<=m){
                maxc=i-j;
                l=j;
            }
        }
        int x=0;
        for(;x<maxc;x++){
            if(arr[l+x]==0)
            cout<<l+x<<" ";
        }
        
        cout<<endl<<endl;
        
        return maxc;
    }
