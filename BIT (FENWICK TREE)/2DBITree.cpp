#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<vector<int>> fenwick, M;

// 2-D BIT 
//For finding Matrix sum from [x1,y1]....[x2,y2] rectangle
//Also point updates available

 void update(int i,int j,int val){
  int xdash = i;

  while(xdash < M.size()){
    int ydash=j;

    while(ydash < M[0].size()){
      fenwick[xdash][ydash] += val;
      ydash += (ydash & -ydash);
    }
    xdash += (xdash & -xdash);
  }
}

void preprocess(){
  for(int i=1;i<M.size();++i)
    for(int j=1;j<M[0].size();++j)
      update(i,j,M[i][j]);
}

int calSum(int i,int j){
  int xdash = i;
  int sum{};

  while(xdash){
    int ydash=j;

    while(ydash){
      sum += fenwick[xdash][ydash];
      //cout<<fenwick[xdash][ydash]<<" dd\n\n";
      ydash -= (ydash & -ydash);
    }
    xdash -= (xdash & -xdash);
  }
  return sum;
}
int sum(int x1,int y1,int x2,int y2){
  int inc1 = calSum(x2, y2);
  int inc2 = calSum(x1-1,y1-1);
  int exc1 = calSum(x1-1, y2);
  int exc2 = calSum(x2,y1-1);
  //cout<<"\n\n\n";
  //cout<<inc1<<" "<<inc2<<" "<<exc1<<" "<<exc2<<endl;

  return inc1 + inc2 - exc1 - exc2;
}
void solve() {
    int n,m;
    cin>>n>>m;

    M.resize(n+1);
    for(int i=0;i<=n;i++)
      M[i].resize(m+1);

    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
        cin>>M[i][j];

    fenwick.resize(n+1);
    for(int i=0;i<=n;++i)
      fenwick[i].resize(m+1);

    preprocess();
    
    /*
    for(int i=1;i<=n;++i){
      for(int j=1;j<=m;++j){
        cout<<fenwick[i][j]<<" ";}
        cout<<'\n';}

        */

    
    int q;
    cin>>q;

    while(q--){
      char ch;
      cin>>ch;

      if(ch=='u'){
        int val, i,j;
        cin>>i>>j>>val;
        update(i,j,val);
      }
      else{
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<sum(x1,y1,x2,y2)<<'\n';
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
