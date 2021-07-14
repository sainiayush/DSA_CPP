int binary_search(int* arr, int low,int high,int x){

  while(low<=high){
    int mid=low + (high-low)/2;

    if(arr[mid]==x){
      return mid;
    } else if(arr[mid]<x){
      low=mid+1;
    } else {
      high=mid-1;
    }
  }
  return -1;
}
int exponential_search(int arr[],int n,int x){
  
  if(arr[0]==x)
  return 0;

  int i=1;

  while(i<n && arr[i]<=x){
    i*=2;
  }

  return binary_search(arr,i/2,min(i,n-1),x);
}
