#include<bits/stdc++.h>

using namespace std;

void moveZeroes (int arr[], int n)
{
  int j=0;
  for(int i=0;i<n;i++){
   if(arr[i]!=0)
     swap(arr[i],arr[j++]);
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
      
      cout<<majorityElement(arr,n);
    
    for (int i = 0; i < n; i++)
	      cout<<arr[i];
    cout<<endl;
    }
  return 0;
}
