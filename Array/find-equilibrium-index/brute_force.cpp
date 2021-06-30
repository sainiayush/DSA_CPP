#include<bits/stdc++.h>

using namespace std;

int findEquilibriumindex (int arr[], int n)
{
  int leftsum=0, rightsum=0;


  for(int i=0;i<n;i++){

    leftsum=0;
    for(int j=0;j<i;j++){
      leftsum+=arr[j];

    rightsum=0;
    for(int k=i+1;k<n;k++)
    rightsum+=arr[k];

    if(leftsum==rightsum)
    return i;
    }
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
