#include <bits/stdc++.h>


using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)            cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");
template<class T> void print_set(const set<T>& c, const string& set_name = "") {
  cerr << (!set_name.empty() ? set_name : "   Set : ") << "{ ";
  for(auto it = c.begin(); it != c.end(); ++it) {
    if (it != c.begin()) cerr << " , ";
    cerr << *it;
  }
  cerr << " } " << c.size() << " Elements." << endl;
}

const int limit = 1300000;

vector<bool> is_prime(limit, true);
vector<int> primes;

void get_first_100000_primes() {
  primes.reserve(100000);

  is_prime[0] = is_prime[1] = false;

  for(int i = 2; i <= sqrt(limit); ++i) {
    if (is_prime[i]) {
      for(int j = i * i; j < limit; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < limit && primes.size() < 100000; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}
bool is_solution(const vector<int>& p) {
  for(int i = 0; i < p.size(); ++ i) {
    if (!is_prime[abs(p[i] - (i+1))]) {
      return false;
    }
  }
  return true;
}
void brute_force(int limit) {
  for(int permutation_size = 3; permutation_size <= limit; ++ permutation_size){
    vector<int> vec(permutation_size);
    iota(vec.begin(), vec.end(), 1);
    bool solution_found = false;
    vector<int> solution;
    do{
      if( is_solution(vec) ) {
        solution_found = true;
        solution = vec;
        break;
      }
    } while(next_permutation(vec.begin(), vec.end()));
    if( !solution_found ) {
      cerr << "No solution found for " << permutation_size << endl;
    } else {
      cerr << "Solution found for " << permutation_size << " " ;
      va(solution);
    }
  }
}
vector<int> brute_force_solution(int permutation_size) {
  vector<int> vec(permutation_size);
  iota(vec.begin(), vec.end(), 1);
  bool solution_found = false;
  vector<int> solution;
  do{
    if( is_solution(vec) ) {
      solution_found = true;
      solution = vec;
      break;
    }
  } while(next_permutation(vec.begin(), vec.end()));
  return solution;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  get_first_100000_primes();
  
  //brute_force(20);
  //va(primes);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for( int current_test = 1; current_test <= test_cases; ++ current_test ) {
    cerr << "\nTest case " << current_test << endl;
    solve();
  }
  return 0;
}

void print_solution( const vector<int>& solution_vector ) {
  for( int i = 0; i < solution_vector.size(); ++ i) 
    cout << (i > 0 ? " " : "") << solution_vector[i];
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  if( n <= 3 ) {
    cout << -1 << endl;
    return;
  }
  if( n <= 8 ) {
    vector<int> solution = brute_force_solution(n);
    print_solution(solution);
    return;
  }
  vector<vector<int>> saved = {
    {3, 4, 1, 2},
    {3, 4, 5, 1, 2},
    {3, 4, 5, 6, 2, 1},
    {3, 4, 5, 6, 7, 1, 2}
  };
  vector<int> ans(n + 1, 0);
  while(n > 7) {
    ans[n] = n - 2;
    ans[n-2] = n;
    ans[n-1] = n - 3;
    ans[n-3] = n - 1;
    n -= 4;
  }
  for(int j = 1; j <= n; ++j) {
    ans[j] = saved[n-4][j-1];
  }
  for(int j = 1; j < ans.size(); ++j) {
    cout << ans[j];
    if(j < ans.size() - 1) 
        cout << " ";
  }
  cout << endl;
}
