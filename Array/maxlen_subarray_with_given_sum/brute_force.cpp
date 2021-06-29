#include<bits/stdc++.h>

using namespace std;

int largestsubarray(int arr[], int n,int sum)
{
  int maxlenArray=INT_MIN, sum_array=0;
  
  for(int i=0;i<n;i++){
    sum_array+=arr[i];
    
   for(int j=i+1;j<n;j++){
  sum_array+=arr[j];
      if(sum_array==sum){
   maxlen=max(maxlen,j-i+1);
   }
   }
  }
  return maxlen;
}

int
main ()
{

  int t;
  cin >> t;

  while (t--)
    {
      int n,k;
      cin >> n>>k ;
      int *arr = new int[n];

      for (int i = 0; i < n; i++)
	      cin >> arr[i];
      cout<<largestsubarray(arr,n)<<endl;
      
    }
  return 0;
}
