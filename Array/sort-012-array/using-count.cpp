#include<bits/stdc++.h>

using namespace std;

void sort012usingcount (int arr[], int n)
{
  int count0=0, count1=0;
  for (int i = 0; i < n; i++)
  {
    if(arr[i]==0)
    count0++;
    if(arr[i]==1)
    count1++;
  }
  
    int k=0;

    while(k<count0)
    arr[k++]=0;

    while(k<count0+count1)
    arr[k++]=1;

    while(k<n)
    arr[k++]=2;
}

int main()
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
      
      sort012usingcount(arr,n);
      cout<< endl;
    }
  return 0;
}
