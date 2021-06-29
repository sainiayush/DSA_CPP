#include<bits/stdc++.h>

using namespace std;

int duplicate(int arr[], int n)
{
  sort(arr,arr+n);
  
  for(int i=1;i<n;i++){
   if(arr[i-1]==arr[i])
     return arr[i];
  }
  return -1;
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
      cout<<duplicate(arr,n)<<endl;
    }
  return 0;
}
