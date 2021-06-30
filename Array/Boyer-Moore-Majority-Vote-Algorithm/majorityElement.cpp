#include<bits/stdc++.h>

using namespace std;

int majorityElement (int arr[], int n)
{
  int count=1, majority=arr[0];

  for(int i=1;i<n;i++){
    if(arr[i]==majority){
      count++;
    } else{
      count--;
    }  if(count==0){
      majority=arr[i];
      count=1;
    } 
  }

  count=0;

  for(int i=0;i<n;i++){
    if(arr[i]==majority){
      count++;
    }
  }
  if(count > n/2)
  return majority;
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
      
      cout<<majorityElement(arr,n)<<endl;
    }
  return 0;
}
