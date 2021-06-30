#include<bits/stdc++.h>

using namespace std;

int maxSum (int arr[], int n)
{
  int sum=0, max_sum=0;
  
  for(int i=0;i<n;i++){
    sum=0;
   for(int j=i;j<n;j++){
    sum+=arr[j];
     max_sum = max(max_sum,sum);
     if(sum<0)
       sum=0;
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
