#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class lazy_prop{
  private : 
    vector<int> tree, lazy, _nums;
    int sz, max_sz;

  public:
    lazy_prop(vector<int>& nums){
      sz = nums.size();
      _nums.resize(sz);
      _nums=nums;
      int k =ceil(log2(sz));
      max_sz = 2*pow(2,k)-1;

      tree.resize(max_sz);
      lazy.resize(max_sz);
      build(1,0,sz-1);
    }

    inline int query(int l,int r){
      if(l>r or l<0 or r>sz-1){
        cout<<"Invalid Query \n Exiting.....";
        exit(0);
      }
      return query(1,0,sz-1,l,r);
    }

    inline void updateRange(int l,int r,int val){
      if(l>r or l<0 or r>sz-1){
        cout<<"Invalid Query \n Exiting.....";
        exit(0);
      }
      updateRange(1,0,sz-1, l,r,val);
    }

  private:
  inline void updateRange(int node, int start,int end,int l,int r,int val){
    if(lazy[node]){
        tree[node] += (end-start+1)*lazy[node];

        if(start!=end){
          lazy[2*node] += lazy[node];
          lazy[2*node+1] += lazy[node];
        }

        lazy[node]=0;
      }

      if(start>end or l>end or start>r)
        return ;
      
      if(l<=start and r>=end){
        tree[node] += (end-start+1)*val;

        if(start!=end){
          lazy[2*node] += val;
          lazy[2*node+1] += val;
        }

        return;
      }

      int mid = start + ((end-start)>>1);
      int left = 2*node, right = 2*node+1;

      updateRange(left, start, mid, l, r, val);
      updateRange(right, mid+1, end, l, r, val);

      tree[node] = tree[left] + tree[right];
  }
    inline int query(int node, int start,int end,int l,int r){
      if(lazy[node]){
        tree[node] += (end-start+1)*lazy[node];

        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];

        lazy[node]=0;
      }

      if(start>end or l>end or start>r)
        return 0;
      
      if(l<=start and r>=end)
        return tree[node];

      int mid = start + ((end-start)>>1);
      int left = 2*node, right = 2*node+1;
      return query(left,start,mid,l,r) + query(right, mid+1, end,l,r);
    }
    inline void build(int node, int start, int end){
      if(start > end)
        return;
      if(start==end){
        tree[node]=_nums[start];
        return;
      }

      int mid = start + ((end-start)>>1);
      int left = 2*node, right = 2*node+1;

      build(left, start, mid);
      build(right, mid+1, end);

      tree[node]=tree[left]+tree[right];
    }
};
void solve() {
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int &x: vec)  
      cin>>x;

    int q;
    cin>>q;
    
    lazy_prop la(vec);
    while(q--){
      char ch;
      cin>>ch;

      if(ch=='q'){
        int l,r;
        cin>>l>>r;

        cout<<la.query(l,r)<<'\n';
      }else{
        int l,r,val;
        cin>>l>>r>>val;

        la.updateRange(l,r, val);
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
