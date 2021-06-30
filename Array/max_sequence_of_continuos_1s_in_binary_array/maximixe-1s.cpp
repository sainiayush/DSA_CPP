 int findZeroes(int arr[], int n, int m) {
        int count=0,i=0,j=-1,maxc=0;
        
        while(i<n){
            if(arr[i]==0)
            count++;
            
            while(count>m){
                j++;
                if(arr[j]==0)
                count--;
            }
           
            maxc=max(i-j,maxc);
            i++;
        }
        return maxc;
    }  
