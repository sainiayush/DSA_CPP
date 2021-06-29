#include<bits/stdc++.h>

using namespace std;

int largestsubarray(int arr[], int n)
{
  int maxlenArray=INT_MIN, len=1, start=0, end=0,beg=0;
  
  for(int i=1;i<n;i++){
    if(arr[i-1]+1==arr[i]){
      len++;
    start=beg;
      end=i;
      if(maxlen<len)
        maxlen=len;
    } else{
    beg=i+1;
      len=0;
     }
   }
  return end-start+1;
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
      cout<<largestsubarray(arr,n)<<endl;
      
    }
  return 0;
}
