import sys
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines().strip()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().strip().split()]
def LF(): return [float(x) for x in sys.stdin.readline().strip().split()]
def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))

def LS(): return sys.stdin.readline().strip().split()
def I(): return int(sys.stdin.readline().strip())
def F(): return float(sys.stdin.readline().strip())
def S(): return sys.stdin.readline().strip()


def solve():
    a = LI()
    a.sort()
    print("YES" if a[0] + a[1] == a[2] else "NO")

def main():
    test_count = I()
    for _ in range(test_count):
        solve()

if __name__ == "__main__":
    main()