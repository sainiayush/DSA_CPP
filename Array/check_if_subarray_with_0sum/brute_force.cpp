#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> check0sumpair (int arr[], int n)
{
  vector<pair<int,int>> ans;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]+arr[j]==0)
        ans.push_back({arr[i],arr[j]});
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
      int n;
      cin >> n ;
      int *arr = new int[n];

      for (int i = 0; i < n; i++)
	      cin >> arr[i];
      
      vector<pair<int,int>>findPair =check0sumpair(arr,n);
      
      for(pair<int,int>x: findPair){
        cout<<x.first<<" "<<x.second<<"\n";
      }

      cout<< endl;
    }
  return 0;
}
