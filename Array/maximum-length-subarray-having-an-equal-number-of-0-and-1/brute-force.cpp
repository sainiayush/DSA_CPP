#include<bits/stdc++.h>

using namespace std;

int maxlen01subarray (int arr[], int n)
{
  int sum=0, maxlen=-1;
  for(int i=0; i<n-1; i++){
    sum=(arr[i]==0)?-1:1;
    for(int j=i+1;j<n;j++){
      (arr[j]==0)?sum+=-1:sum+=1;
      if(sum==0 && maxlen<j-i+1){
        maxlen=j-i+1;
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
      int n;
      cin >> n ;
      int *arr = new int[n];

      for (int i = 0; i < n; i++)
	      cin >> arr[i];
      
      

      cout<<maxlen01subarray(arr,n)<< endl;
    }
  return 0;
}
