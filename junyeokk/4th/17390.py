import sys
input = sys.stdin.readline

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

prefix_sum = [0] * (n + 1)
for i in range(n):
  prefix_sum[i + 1] = prefix_sum[i] + a[i]
 
for i in range(q):
  start, end = map(int, input().split())
  print(prefix_sum[end] - prefix_sum[start - 1])