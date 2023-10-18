#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases; 
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    //cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for( int i = 0; i < n; ++ i) cin >> a[i]; 
  //va(a);

  if( n == 1 ) {
    cout << a[0] << '\n';
    return;
  }
  long long sum = accumulate(a.begin(), a.end(), 0LL);
  vector<long long> max_element_in_prefix(n, a[0]);
  for (int i = 1; i < n; ++i) {
    max_element_in_prefix[i] = max(max_element_in_prefix[i - 1], a[i]);
  }

  vector<long long> max_element_in_suffix(n, a[n - 1]);
  for (int i = n - 2; i >= 0; --i) {
    max_element_in_suffix[i] = max(max_element_in_suffix[i + 1], a[i]);
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += min(max_element_in_prefix[i], max_element_in_suffix[i]);
  }
  //debug(res, sum);
  //va(max_element_in_prefix);
  //va(max_element_in_suffix);
  cout << max(res, sum) << endl;
}
