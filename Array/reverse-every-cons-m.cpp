void reverse(int *arr,int n,int k){
 
  int k=k%n;
  
  int start=0, end=k-1;
  for(int i=0;i<n-k;i+=k){
    start=i;
    end= min(n-1,i+k-1);
    while(start<end){
     swap(arr[start++],arr[end--]); 
    }
  }
}
