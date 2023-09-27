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
const long long MODULO = 1e9 + 7;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  long long answer = 1;
  for( int i = 2;i < s.size(); i+=2 )
  {
    long long factor = 0;
    bool a = s[i-1] == '1';
    bool b = s[i-2] == '1';
    bool c = s[i] == '1';
    //debug(i,a,b,c);
    if( (a && b) == c ) ++factor;
    if( (a || b) == c ) ++factor;
    if( (a ^ b) == c ) ++factor;


    answer = (answer * factor) % MODULO;
  }
  cout << answer%MODULO << endl;
}
