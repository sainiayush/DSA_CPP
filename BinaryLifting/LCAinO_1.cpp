#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
*/
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define all(container) container.begin(), container.end()
#define allr(container) container.rbegin(), container.rend()
#define SORT(container) sort(all(container))
#define SORTR(container) sort(allr(container))
#define UNIQUE(container) sort(all(container)), x.erase(unique(all(x)), x.end())
#define cnt(s, c) count(all(s), c)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define len(container) (int)(container).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DBL(...)\
    double __VA_ARGS__;\
    IN(__VA_ARGS__)
#define TEST \
INT(testcases); \
while(testcases--)
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size); \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)\
    vector<vector<type>> name(h, vector<type>(w)); \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define mt make_tuple
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define MIN(container) min_element(all(container))
#define MAX(container) max_element(all(container))
#define SUM(container) accumulate(all(container), 0ll)
template<typename T> static constexpr T inf = numeric_limits<T>::max()/2;
const double EPS = 1E-9;
const int INF = 1000000000;
const ll INF64 = (ll) 1E18;
const double PI = 3.1415926535897932384626433832795;
constexpr int MOD = 1e9+7;
constexpr int MOD2 = 998244353;
template <class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 
template<typename _Tp>
istream& operator >> (istream& i, vector<_Tp>& v){
  for(_Tp& x : v)
    i >> x;
  return i;
}
template<typename _Tp1, typename _Tp2>
istream& operator >> (istream& i, pair<_Tp1, _Tp2>& v){
  i >> v.ff >> v.ss;
  return i;
}
template<class T>
vector<T>& operator -- (vector<T>& v){
  for(T&x: v) --x;
  return v;
}
template<class T>
vector<T>& operator ++ (vector<T>& v){
  for(T&x: v) ++x;
  return v;
}
template<class T> 
pair<T, T>& operator -- (pair<T, T>& v){
    --v.ff, --v.ss;
    return v;
}
template<class T> 
pair<T, T>& operator ++ (pair<T, T>& v){
    ++v.ff, ++v.ss;
    return v;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto it = begin(v); it != end(v); ++it) {
        if(it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}

//order statistic tree
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//cout << s.order_of_key(3) << endl; // the number of elements in s less than 3 (in this case, 0-based index of element 3)
//cout << *s.find_by_order(1) << endl; // 1-st elemt in s (in sorted order, 0-based)

vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}

void DFS(int node, int par, vector<int>& travel, vector<int>& start, vector<int>& lvl, vector<vector<int>>& g){
  start[node]=len(travel);
  travel.eb(node);

  for(auto v: g[node]){
    if(v != par){
      lvl[v]=lvl[node]+1;
      DFS(v, node, travel, start, lvl, g);
      travel.eb(node);
    }
  }
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  INT(tt);
  for(int t=1; t<=tt; ++t){
    INT(n);
    vector<vector<int>> g(n+1);
    for(int i=1; i<=n ;++i){
      INT(cnt);
      for(int j=0; j<cnt; ++j){
        INT(node);
        g[i].eb(node);
      }
    }

    vector<int> travel, start(n+1), lvl(n+1);
    DFS(1, 0, travel, start, lvl, g);

    lvl[0]=INT_MAX;
    int k=log2(len(travel))+1;
    vector<vector<int>> sparse(k, vector<int>(len(travel)));
    sparse[0]=travel;

    for(int j=1; j<k; ++j)
      for(int i=0; i+(1<<j) <= len(travel); ++i){
        int u=sparse[j-1][i];
        int v=sparse[j-1][i+(1<<(j-1))];
        sparse[j][i] = (lvl[u] > lvl[v] ? v : u);
      }
    cout << "Case "<<t << ":\n";
    TEST{
      INT(u, v);
      int mini = min(start[u], start[v]);
      int maxi = max(start[u], start[v]);
      int cnt=maxi-mini+1;
      int k=log2(cnt);

      int a=sparse[k][mini];
      int b=sparse[k][maxi - (1<<k) + 1];
      cout << (lvl[a] > lvl[b] ? b : a) << endl;
    }
  }
  return 0;
}