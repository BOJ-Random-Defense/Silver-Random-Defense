import sys
input = sys.stdin.readline

n, l = map(int, input().split())

for k in range(l, 101):
  a = (n - k * (k - 1) / 2) / k

  if a >= 0 and a == int(a):
    a = int(a)
    print(*range(a, a + k))
    break
else:
  print(-1)