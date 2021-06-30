#include<bits/stdc++.h>

using namespace std;

void implacemerge (int x[],int y[], int n1,int n2)
{
  
  for(int i=0;i<n1;i++){
    
    if(y[0]<x[i])
    swap(x[i],y[0]);

    int first=y[0];
    int k=0;
    for(k=1;k<n2 && first>y[k];k++){
      y[k-1]=y[k];
    }
    y[k-1]=first;
  }
}

int main ()
{

  int t;
  cin >> t;

  while (t--)
    {
      int n1,n2;
      cin >> n1>> n2 ;

      int *arr1 = new int[n1];
      for (int i = 0; i < n1; i++)
	      cin >> arr1[i];
      
      int *arr2= new int[n2];
      for (int i = 0; i < n2; i++)
	      cin >> arr2[i];

      implacemerge (arr1,arr2,n1,n2);
      cout<< endl;
    }
  return 0;
}
