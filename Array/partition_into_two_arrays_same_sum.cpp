#include<bits/stdc++.h>

using namespace std;

int partitionintoTwo(int *arr, int n){
 
  int i=0;
  int sum=accumulate(arr,arr+n,0), lsum=0;
  
  for(int i=0;i<n;i++){
    sum-=arr[i];
    
    if(lsum==sum)
      return i;
    
    lsum+=arr[i];
  }
  return -1;
}
int main(){
 
  int n;
  cin>>n;
  
  int *arr=new int[n];
  
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  int p= partitionintoTwo(arr,n);
  
  if(p!=-1){
   copy(arr,arr+i,ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(arr+i,arr+n,ostream_iterator<int>(cout, " "));
    
  } else 
    cout<<"Array cannot be partitioned";
  
  return 0;
}
