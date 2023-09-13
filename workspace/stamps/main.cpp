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
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for( int i = 0; i < n-2; i ++ ) {
    if( s[i] == '0' ) continue;
    if( s[i] == '1' ) {
      for( int j = i+1; j < n; ++ j ) {
        s[j] = '0';
      }
      break;
    }
  }
  cout << s << endl;
}
