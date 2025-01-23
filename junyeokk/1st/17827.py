import sys
input = sys.stdin.readline

n, m, v = map(int, input().split())
arr = list(map(int, input().split()))

for i in range(m):
  cnt = int(input())

  if cnt < n:
    print(arr[cnt])
  else:
    remain = (cnt - n) % (n - v + 1)
    print(arr[v - 1 + remain])