#include<bits/stdc++.h>

using namespace std;

int findEquilibriumindex (int arr[], int n)
{
  int forward[n]={0}, rev[n]={0};
  
  for(int i=0;i<n;i++){
   if(i){
   forward[i]=forward[i-1]+arr[i];
   }else{
   forward[i]=arr[i];
   }
  }
  
  for(int i=n-1;i>=0;i++){
   if(i<=n-2){
    rev[i]=rev[i+1]+arr[i]; 
   } else{
    rev[i]=arr[i];
   }
  }
  
  for(int i=0;i<n;i++)
    if(forward[i]==rev[i])
      return i;
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
