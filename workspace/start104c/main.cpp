#include <bits/stdc++.h>


using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

template<class T> T gcd(T a,T b) {if (a<0) a=-a;if (b<0) b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> T lcm(T a,T b) {return (a/gcd(a,b))*b;}
vector<vector<int>> divisors;

void precompute_divisors(int M) {
  divisors.assign(M + 1, vector<int>());
  for (int i = 1; i <= M; ++i) {
    for (int j = i; j <= M; j += i) {
      divisors[j].push_back(i);
    }
  }
}

int find_next(int M, int current_gcd, int ai) {
  if (ai == current_gcd) {
    // search for the largest divisor of current_gcd which isn't current_gcd itself
    for (int i = divisors[current_gcd].size() - 2; i >= 0; --i) {
      int d = divisors[current_gcd][i];
      if (d <= M) return d;
    }
  } else {
    for (int d : divisors[ai]) {
      if (d <= M && gcd(d, current_gcd) == ai) return d;
    }
  }
  return 1;  // Ideally shouldn't reach here
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> b(n);
  b[0] = a[0];
  int current_gcd = b[0];

  for (int i = 1; i < n; ++i) {
    b[i] = find_next(m, current_gcd, a[i]);
    current_gcd = gcd(current_gcd, b[i]);
  }

  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int test_cases = 1;
  cin >> test_cases;

  int max_m = 0;
  for (int current_test = 1; current_test <= test_cases; ++current_test) {
    int n, m;
    cin >> n >> m;
    max_m = max(max_m, m);
  }

  precompute_divisors(max_m);

  for (int current_test = 1; current_test <= test_cases; ++current_test) {
    solve();
  }

  return 0;
}
