#include<bits/stdc++.h>

using namespace std;

void rearrangehilo (int arr[], int n)
{
  int lo=0,hi=n-1, flag=0;

  int *temp= new int[n];

  for(int i=0;i<n;i++){
    if(!flag){
      temp[i]=arr[hi--];
      flag=1;
    } else{
      temp[i]=arr[lo++];
      flag=0;
    }
  }
  for(int i=0;i<n;i++){
    arr[i]=temp[i];
  }
  
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
      
      rearrangehilo(arr,n);

      for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
      cout<< endl;
    }
  return 0;
}
