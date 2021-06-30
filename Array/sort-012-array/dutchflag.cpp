#include<bits/stdc++.h>

using namespace std;

void sort012usingdutchnationalflag (int arr[], int n)
{
  int mid=0, lo=0, hi=n-1;

  while(mid<=hi){
    switch(arr[mid]){
      case 0: 
      swap(arr[mid++],arr[lo++]);
      break;

      case 1: 
      mid++;
      break;

      case 2: 
      swap(arr[mid++],arr[hi--]);
      break;
    }
  }
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
      
      sort012usingdutchnationalflag (arr,n);
      cout<< endl;
    }
  return 0;
}
