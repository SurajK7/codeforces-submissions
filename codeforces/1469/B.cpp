#include <bits/stdc++.h>
using namespace std;  
 
#define PRINT(x) cout << '>' << #x << ':' << x << endl; 
#define REP(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORD(i,a,b) for(int i=(a);i>=(b);i--) 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; } 
 
const int INF = 1<<29; 
typedef long long ll; 
 
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; } 
 
template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 
///////////////////////////////////////////////////////////////////// 
 
void solve() 
{
    int n;
    cin >> n;
    vector <int> r(n);
    REP(i, n) cin >> r[i];
    int m;
    cin >> m;
    vector <int> b(m);
    REP(i, m) cin >> b[i];
    // cout << "-----------------" << endl;
    // cout << n << endl;
    // REP(i, n) cout << r[i] << " ";
    // cout << endl;
    // cout << m << endl;
    // REP(i, m) cout << b[i] << " ";
    // cout << endl;
    int maxr = r[0];
    int sumr = r[0];
    FOR(i, 1, n-1)
    {
        sumr+=r[i];
        maxr = max(sumr, maxr);
    }
    int maxb = b[0];
    int sumb = b[0];
    FOR(i, 1, m-1)
    {
        sumb+=b[i];
        maxb = max(sumb, maxb);
    }
    cout << max(0, maxr)+max(0, maxb) << endl;
}
 
int main() 
{ 
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) 
    {
        solve();
    }
    return 0; 
}