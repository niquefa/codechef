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
  string s;
  cin >> s;
  int n = s.size();
  vector<char> letters;
  vector<int> repetitions;
  for( int i = 0; i < n; ++ i ) {
    if( letters.empty() || letters.back() != s[i] ) {
      letters.push_back(s[i]);
      repetitions.push_back(1);
    } else {
      repetitions.back() ++;
    }
  }
  for( int i = 0; i < letters.size(); ++ i ) {
    cout << letters[i];
    if( repetitions[i] > 1 ) 
      cout << repetitions[i];
  }
  cout << endl;
}
