import sys
from typing import List
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines().strip()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().strip().split()]
def LF(): return [float(x) for x in sys.stdin.readline().strip().split()]
def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def LS(): return sys.stdin.readline().strip().split()
def I(): return int(sys.stdin.readline().strip())
def F(): return float(sys.stdin.readline().strip())
def S(): return sys.stdin.readline().strip()

def debug(*args):
  print(*args, file=sys.stderr)

class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    print(grid)
    pass

def main():
  test_count = I()
  for test_case in range(test_count):
    debug("Test " + str(test_case + 1) + ":")
    

    R, C = MI()
    debug(R,C)
    grid = []
    for _ in range(R):
      grid.append(list(LS()))

    for row in grid:
      debug(row)
    debug("")
    

    sol = Solution()
    answer = sol.numIslands(grid)
    print(answer)

if __name__ == "__main__":
    main()