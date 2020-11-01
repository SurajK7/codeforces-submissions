#include <bits/stdc++.h>

using namespace std;

string test(int n, int x, int *a, int *b)
{
    for (int i=0; i<n; i++){
        if(a[i]+b[n-i-1]>x){
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << test(n, x, a, b) << endl;
    }
}