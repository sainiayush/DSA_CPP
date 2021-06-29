#include<bits/stdc++.h>

using namespace std;

int duplicateusingHashing(int arr[], int n)
{
  unordered_map<int,int>freq;
  
  for(int i=0;i<n;i++){
  freq[arr[i]]++;
  }
  
  for(auto it:mp){
   if(it->second>1)
     return it->first;
  }
  return -1;
  
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
      cout<<duplicateusingHashing(arr,n)<<endl;
      
    }
  return 0;
}
