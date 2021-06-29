#include<bits/stdc++.h>

using namespace std;

bool findPair (int arr[], int n, int x)
{

  

  sort(arr,arr+n);

  int lo=0, hi=n-1;

  while(lo<hi){
    int mid = lo + (hi-lo)/2;
    if(arr[lo]+arr[hi]==x)
    return true;
    else if(arr[lo]+arr[hi]<x)
    lo++;
    else--hi;

  }
  return false;
}

int
main ()
{

  int t;
  cin >> t;

  while (t--)
    {
      int n, sum;
      cin >> n >> sum;
      int *arr = new int[n];

      for (int i = 0; i < n; i++)
	cin >> arr[i];

      findPair (arr, n, sum);

    if(findPair)
    cout<<"1";
    else
    cout<<"0";
      cout << endl;
    }
  return 0;
}
