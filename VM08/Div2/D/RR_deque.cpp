#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

vector<int> primes;
int sieve[1000111];

void init() {
    FOR(i,2,1000000) if (!sieve[i]) {
        primes.push_back(i);
        for(int j = i*i; j < 1000111; j += i) {
            sieve[j] = 1;
        }
    }
}

deque<int> qu;
string s;

void add(int i) {
    while (!qu.empty() && s[qu.back()] < s[i]) qu.pop_back();
    qu.push_back(i);
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    init();
    int n, k;
    while (cin >> n >> k) {
        stringstream ss;
        REP(i,n) ss << primes[i];
        
        s = ss.str();

        n = SZ(s);

        // Có thể chọn chữ số tiếp theo trong [0, v]
        int v = n - (n-k);

        qu.clear();
        FOR(i,0,v) add(i);

        FOR(i,1,n-k) {
            // Lấy ra chữ số to nhất, trái nhất.
            int t = qu.front(); qu.pop_front();
            cout << (char) s[t];

            // Cập nhật những vị trí có thể chọn chữ số tiếp theo.
            ++v;
            add(v);
        }
        cout << endl;
    }
}


