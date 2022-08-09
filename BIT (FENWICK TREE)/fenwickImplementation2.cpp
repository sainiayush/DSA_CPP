#include <bits/stdc++.h>
using namespace std;

//BIT preprocessing in O(N)
int prefixSum(int idx, vector<int> &fen){
  idx++;
  int sum{};

  while(idx){
    sum += fen[idx];
    idx -= (idx&-idx);
  }
  return sum;
}

void update(int val, int pos,vector<int>& arr, vector<int>& fen){
  if(val!=arr[pos]){
    int delta = val - arr[pos];
    arr[pos]=delta;
    pos++;
    while(pos < fen.size()){
      fen[pos] += delta;
      pos += pos&-pos;
    }
  }
}
int sum(int l,int r, vector<int>& fen){
  return prefixSum(r,fen) - prefixSum(l-1,fen);
}
void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &x: arr)  
      cin>>x;

    vector<int> fen(n+1), pre={0};
    for(int i=0;i<n;++i)
      pre.emplace_back(pre.back() + arr[i]);

    for(int i=1;i<=n;++i){
      int idash = i-(i & (-i));
      fen[i] = pre[i] - pre[idash];
    }

    int q;
    cin>>q;

    while(q--){
      char ch;
      cin>>ch;

      if(ch=='u'){
        int val, pos;
        cin>>val>>pos;

        update(val,pos,arr,fen);
      }
      else{
        int l,r;
        cin>>l>>r;

        cout<<sum(l,r,fen)<<'\n';
      }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
