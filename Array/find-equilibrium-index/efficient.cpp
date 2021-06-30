#include<bits/stdc++.h>

using namespace std;

int findEquilibriumindex (int arr[], int n)
{
  int sum= accumulate(arr,arr+n,0);
  int lsum=0;
  for(int i=0;i<n;i++){
    sum-=arr[i];

    if(lsum==sum)
    return i;

    lsum+=arr[i];
  }
  return -1;
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
      
      cout<<findEquilibriumindex(arr,n)<<endl;
    }
  return 0;
}
