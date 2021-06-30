#include<bits/stdc++.h>

using namespace std;

void rearrangehilo (int arr[], int n)
{
  int max_el=arr[n-1]+1;
  int maxidx=n-1, minidx=0;

  for(int i=0; i < n; i++){
    if(i%2==0){
      arr[i]+= (arr[maxidx]%max_el)*max_el;
      maxidx--;
    } else{
      arr[i]+= (arr[minidx]%max_el)*max_el;
      minidx++;
    }
  }
  
  for(int i=0; i < n; i++){
    arr[i]/=max_el;
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
