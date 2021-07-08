void multiply(vector<int>& arr, int x){
  
  int carry=0;
  
  for(int i=0;i<arr.size();i++){
   int prod = arr[i]*x+carry;
    carry=prod/10;
    arr[i]=prod%10;
  }
  while(carry){
   ans.push_back(carry%10);
    carry/=10;
  }
}
vector<int> Factorial(int n){
  
  vector<int>ans;
  ans.push_back(1);
  
  for(int x=2;x<=2;x++)
    multiply(arr,x);
  
  reverse(arr.begin(),arr.end());
  
  return ans;

  
}
