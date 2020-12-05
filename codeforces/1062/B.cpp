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
    int n;
    cin >> n;
    int orig_n = n;
    vector<int> pf;
    vector<int> fp;
    if (n<=1) 
    {
        cout << n << ' ' << 0 << endl;
        return;
    }
    FOR(i, 2, sqrt(n))
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                if (count == 0) pf.push_back(i);
                count ++;
                n /= i;
                if (n%i!=0) fp.push_back(count);
            }
            
        }
    }
    if (n!=1) 
    {
        pf.push_back(n);
        fp.push_back(1);
    }
    int max_power = *max_element(fp.begin(), fp.end());
    int ans_pow = pow(2, ceil(log2(max_power)));
    int max_num = 1;
    int min_num = 1;
    FOR(i, 0, pf.size()-1)
    {
        max_num*=pow(pf[i], ans_pow);
        min_num*=pf[i];
    }
    if (orig_n==max_num) cout << min_num << ' ' << log2(ans_pow) << endl;
    else cout << min_num << ' ' << log2(ans_pow)+1 << endl;
}

int main() 
{ 
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0; 
} 