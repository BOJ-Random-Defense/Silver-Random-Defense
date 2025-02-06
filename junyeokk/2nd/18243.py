import sys
input = sys.stdin.readline

n, k = map(int, input().split())
INF = int(1e9)
graph = [[INF] * n for _ in range(n)]

for i in range(n):
  graph[i][i] = 0

for _ in range(k):
  a, b = map(int, input().split())
  graph[a - 1][b - 1] = 1
  graph[b - 1][a - 1] = 1

for k in range(n):
  for i in range(n):
      for j in range(n):
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

if any(graph[i][j] > 6 for i in range(n) for j in range(n)):
  print("Big World!")
else:
  print("Small World!")