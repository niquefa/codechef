import sys
import ast
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines().strip()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().strip().split()]
def LF(): return [float(x) for x in sys.stdin.readline().strip().split()]
def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def LS(): return sys.stdin.readline().strip().split()
def I(): return int(sys.stdin.readline().strip())
def F(): return float(sys.stdin.readline().strip())
def S(): return sys.stdin.readline().strip()

def isCenterOfStarGraph(edges, node):
  for edge in edges:
    if node not in edge:
      return False
  return True

def solve():
  line_to_parse = S()
  jagged_array = ast.literal_eval(line_to_parse)
  node = I()
  answer = isCenterOfStarGraph(jagged_array, node)

  #print(node, jagged_array)

  print("true" if answer else "false")



def main():
  test_count = I()
  for _ in range(test_count):
    solve()

if __name__ == "__main__":
  main()