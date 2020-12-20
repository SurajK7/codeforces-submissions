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



void prime_factors(int n, vector <int> &factors)// tc O(sqrt(n)) asc theta(1)
{
    if (n<=1) return;
    FOR(i, 2, sqrt(n))
    {
        int count = 0;
        while (n%i == 0)
        {
            if (count==0) factors.push_back(i);
            n /= i;
            count++;
        }
    }
    if (n!=1) factors.push_back(n);
}

void solve() {
    ll p;
    ll q;
    cin >> p >> q;
    if (p%q!=0 or p<q) cout << p << endl;
    else
    {    
        vector <int> factors;
        prime_factors(q, factors);
        ll res = INT64_MIN;
        for(ll i=0; i<factors.size(); i++)
        {
            ll pc = p;
            while (pc%q==0)
            {
                pc/=factors[i];
            }
            res = max(res, pc);
        }
        cout << res <<endl;
    }
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