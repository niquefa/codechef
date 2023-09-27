#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define va(c)      cerr<<#c << " :  ";for(int JJ=0;JJ<(c).size();++JJ)cerr<<(JJ==0?"[":"")<<c[JJ]<<(JJ==(c).size()-1?"] " + to_string((c).size()) + " Elements\n":" , ");

void printSolution(const vector<int64_t>& answer) {
  for (int i = 0; i < answer.size(); ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << answer[i];
  }
  cout << "\n";
}

void solve() {
  int64_t totalNumberInAnswer, desiredSum;
  cin >> totalNumberInAnswer >> desiredSum;

  int64_t totalEvenNumbersAllowed = totalNumberInAnswer / 2;
  int64_t totalOddNumbersAllowed = totalNumberInAnswer / 2;

  int64_t minSumPossible = totalOddNumbersAllowed + totalEvenNumbersAllowed * 2;
  int64_t maxSumPossible = totalOddNumbersAllowed * 99999 + 100000 * totalEvenNumbersAllowed;
  debug(totalNumberInAnswer,desiredSum,minSumPossible, maxSumPossible);
  if (desiredSum < minSumPossible || desiredSum > maxSumPossible) {
    cout << "-1\n";
    return;
  }
  if (desiredSum % 2 == 0 && totalOddNumbersAllowed % 2 != 0) {
    cout << "-1\n";
    return;
  }
  if (desiredSum % 2 == 1 && totalOddNumbersAllowed % 2 == 0) {
    cout << "-1\n";
    return;
  }


  vector<int64_t> answer(totalNumberInAnswer);
  for (int64_t i = 0; i < totalOddNumbersAllowed; ++i) {
    answer[i] = 1;
    answer[i + totalOddNumbersAllowed] = 2;
  }

  desiredSum -= minSumPossible;
  if (desiredSum == 0) {
    printSolution(answer);
    return;
  }
  if (desiredSum % 2 == 1) {
    cout << "-1\n";
    return;
  }
  int64_t additionToAll = desiredSum / totalNumberInAnswer;
  if (additionToAll % 2 == 1) {
    additionToAll--;
  }
  if (additionToAll == 0) {
    additionToAll = 2;
  }
  for (int i = 0; i < answer.size(); ++i) {
    answer[i] += additionToAll;
    desiredSum -= additionToAll;
    if (desiredSum == 0) {
      printSolution(answer);
      return;
    }
  }
  for (int i = 0; i < answer.size(); ++i) {
    answer[i] += 2;
    desiredSum -= 2;
    if (desiredSum == 0) {
      printSolution(answer);
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cerr << endl;
    solve();
  }
  return 0;
}
