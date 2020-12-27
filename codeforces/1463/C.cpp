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
    int n; cin >> n;
    vector <pair <ll, int> > input(n+2);
    vector <pair <ll, int> > ans(n+1);
    REP(i, n) cin >> input[i].first >> input[i].second;
    input[n] = {INT64_MAX, INT_MAX};
    int destintation = 0;
    int x = 0;
    REP(i, n+1)
    {
        if (destintation==x)
        {
            ans[i] = {input[i].first, x};
            destintation = input[i].second;
            if (abs(destintation-x)>input[i+1].first-input[i].first)
            {
                if (destintation<x) x-=input[i+1].first-input[i].first;
                else x+=input[i+1].first-input[i].first;
            }
            else x=destintation;
        }
        else 
        {
            ans[i] = {input[i].first, x};
            if (abs(destintation-x)>input[i+1].first-input[i].first)
            {
                if (destintation<x) x-=input[i+1].first-input[i].first;
                else x+=input[i+1].first-input[i].first;
            }
            else x=destintation;
        }
    }
    int res = 0;
    REP(i, n)
    {
        int arr[2] = {ans[i].second, ans[i+1].second};
        sort(arr, arr+2);
        if (input[i].second>=arr[0] and input[i].second<=arr[1]) res++;
    }
    // REP(i, n+1) cout << ans[i].first << " " << ans[i].second << endl;
    cout << res << endl;

}
 
int main() 
{ 
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int tc; cin >> tc;
    while (tc--) 
    {
        solve();
    }
    return 0; 
}