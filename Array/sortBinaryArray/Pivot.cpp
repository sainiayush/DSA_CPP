#include<bits/stdc++.h>

using namespace std;

void sortusingPivot (int arr[], int n)
{
  int pivot=1,j=-1;
  
  for(int i=0;i<n;i++){
    if(arr[i]<pivot){
    swap(arr[i],arr[++j]);
    }
  }
  
}

int
main ()
{

  int t;
  cin >> t;

  while (t--)
    {
      int n;
      cin >> n ;
      int *arr = new int[n];

      for (int i = 0; i < n; i++)
	      cin >> arr[i];
      
      sortusingPivot(arr,n);
    cout<<endl;
      
    }
  return 0;
}
