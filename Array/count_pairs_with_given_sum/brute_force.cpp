#include<bits/stdc++.h>

using namespace std;

int countPairs (int arr[], int n, int x)
{
  int count=0;

  for(int i = 0; i < n-1;i++){
    for(int j = i+1; j <n;j++){
      if(arr[i]+arr[j]==x)count++;
    }
  }
  return count;
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
      
      cout<<countPairs (arr,n,sum);
      cout << endl;
    }
  return 0;
}
