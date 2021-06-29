#include<bits/stdc++.h>

using namespace std;

void sortusingcount(int arr[], int n)
{
  int count=0;
  
  for(int i=0;i<n;i++){
    if(arr[i]==0)
      count++;
  }
  int k=0;
  while(k<count){
    arr[k++]=0;
  }
  while(k<n){
    arr[k++]=1;
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
      sortusingcount(arr,n);
      cout<<endl;
  }

      
    }
  return 0;
}
