#include<bits/stdc++.h>

using namespace std;

int largestsubarray(int arr[], int n)
{
  int max_len=1;
  for(int i=0;i<n;i++){
   int mx=arr[i], mn=arr[i];
    for(int j=i+1;j<n;j++){
     mn=min(mn,arr[j]);
      mx=max(mx,arr[j]);
      if(mx-mn==j-i)
        maxlen=max(maxlen,j-i+1);
    }
  }
  return maxlen;
}

int main ()
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
      cout<<largestsubarray(arr,n)<<endl;
      
    }
  return 0;
}
