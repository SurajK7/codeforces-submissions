#include <bits/stdc++.h>
using namespace std;  
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl; 
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

void solve() {
    long long c; cin >> c;
    bool chance = true;
    long long ans = 0;
    while(c>0)
    {
        if (chance)
        {
            if (c%2==1) {
                c--;
                ans++;
            }
            else{
                if (c%4==0 and c>4){
                    c--;
                    ans++;
                }
                else{
                    c/=2;
                    ans+=c;
                }
            }
            chance = not chance;
        }
        else
        {
            if (c%2==1) {
                c--;
            }
            else{
                if (c%4==0 and c>4){
                    c--;
                }
                else{
                    c/=2;
                }
            }
            chance = not chance;
        }
    }
    cout << ans <<endl;
}

int main() 
{ 
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0; 
} 