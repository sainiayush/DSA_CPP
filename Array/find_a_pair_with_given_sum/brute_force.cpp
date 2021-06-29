#include<bits/stdc++.h>

using namespace std;

vector < pair < int, int >> findPair (int arr[], int n, int x)
{

  vector < pair < int, int >>ans;

  for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
	{
	  if (arr[i] + arr[j] == x)
	    ans.push_back ({arr[i], arr[j]});
	}
    }
  return ans;
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

      vector < pair < int, int >>res = findPair (arr, n, sum);

    for (pair < int, int >x :res)
	{
	  cout << x.first << " " << x.second << "\n";
	}
      cout << endl;
    }
  return 0;
}
