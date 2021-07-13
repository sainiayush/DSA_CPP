 int partition (int arr[], int low, int high)
    {
       int pivot=arr[low];
       int i=low+1,j=high;
       
       do{
           while(pivot>arr[i])i++;
           while(pivot<arr[j])j--;
           swap(arr[i],arr[j]);
       }while(i<j);
       swap(arr[low],arr[j]);
       
       return j;
    }
    void quickSort(int arr[], int low, int high)
    {
        while(low<=high){
            int pivot=partition(arr,low,high);
            quicksort(low,pi-1);
            quicksort(pi+1,high);
            
        }
