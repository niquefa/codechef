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
  long long x, y, k;
  cin >> x >> y >> k;
  //debug(x,y,k);
  vector<long long> prev = {x, y};
  vector<long long> pair = {x, y};
  for( int op = 0; op < k; ++ op) {
    //va(pair);
    long long the_gcd = gcd(pair[0],pair[1]);
    
    sort(pair.begin(), pair.end());
    pair[1] = the_gcd;
    long long the_lcm = lcm(pair[0], pair[1]);
    sort(pair.begin(), pair.end());
    pair[1] = the_lcm;

    if( k >= 1 && pair == prev ) {
      cout << pair[0] + pair[1] << '\n'; 
      return;
    }
    prev = pair;
  } 
  cout << pair[0] + pair[1] << '\n'; 
}
