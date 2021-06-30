#include<bits/stdc++.h>

using namespace std;

int maxSum (int arr[], int n)
{
  int max_ending_here=0, max_sum=0;
  
  for(int i=0;i<n;i++){
   max_ending_here+=arr[i];
    
    max_sum=max(max_sum,max_ending_here);
    
    if(max_ending_here<0){
     max_ending_here=0; 
    }
  }
  return max_sum;
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
      
      cout<<maxSum(arr,n)<<endl;
    }
  return 0;
}
