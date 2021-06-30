#include<bits/stdc++.h>

using namespace std;

int maxlen01subarray (int arr[], int n)
{
  int maxlen=-1, sum=0;
  unordered_map<int,int>mp;

  for(int i=0;i<n;i++)
  arr[i]=(arr[i]==0)?-1:1;

  for(int i=0;i<n;i++){
    sum+=arr[i];

    if(sum==0){
      maxlen=i+1;
    }
    if(mp.find(sum)!=mp.end()){
      if(maxlen<i-mp[sum])
      maxlen=i-mp[sum];
    } else{
      mp[sum]=i;
    }
  }

  for(int i=0;i<n;i++){
    arr[i]=(arr[i]==-1)?0:1;
  }

  return maxlen;
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
      
      

      cout<<maxlen01subarray(arr,n)<< endl;
    }
  return 0;
}
