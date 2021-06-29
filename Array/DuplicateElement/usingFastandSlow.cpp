#include<bits/stdc++.h>

using namespace std;

int duplicateusingHashing(int arr[], int n)
{
  
  if(n<=1)
    return -1;
  int fast=arr[0],slow=arr[0];
  
  while(fast!=slow){
   slow=arr[slow];
    fast=arr[arr[fast]];
  }
  fast=0;
  
  while(slow!=fast){
   slow= arr[slow];
    fast=arr[arr[fast]];    
  }
  return slow;
  
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
      cout<<duplicateusingHashing(arr,n)<<endl;
      
    }
  return 0;
}
