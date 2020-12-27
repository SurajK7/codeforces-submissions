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
 

int min_swaps(int *arr, int low, int high, int x, int index)
{
    FOR(i, low, high)
    {
        if (i>index) return 0;
        else if (arr[i]<= x and (i+1>high or arr[i]<=arr[i+1])) continue;
        else if (arr[i]<=x and arr[i]>arr[i+1]) return -1;
        else if (arr[i]>x and x>arr[i+1]) return -1;
        else 
        {
            low=i;
            int temp = arr[low];
            arr[low] = x;
            x= temp;
            break;
        }
    }
    // cout << low << " " << x << endl;
    int ans = min_swaps(arr, low, high, x, index);
    ans = (ans==-1) ? -1 : ans+1;
    return ans;

}






void solve() 
{
    int n, x; cin >> n >> x;
    int arr[n];
    REP(i, n) cin >> arr[i];
    bool sorted = true;
    int index;
    REP(i, n-1) if (arr[i]>arr[i+1]){
         sorted =false;
         index = i;
         }
    if (sorted){
         cout << 0 << endl;
         return;
         }
    cout << min_swaps(arr, 0, n-1, x, index) << endl;
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