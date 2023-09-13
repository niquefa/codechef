import sys

def MI(): return map(int, sys.stdin.readline().strip().split())
def LI(): return list(map(int, sys.stdin.readline().strip().split()))
def I(): return int(sys.stdin.readline().strip())

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
#python3 hello.py < t.in