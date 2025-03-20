from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
grid = []

for _ in range(n):
  grid.append(list(map(int, input().strip())))

visited = [[-1 for _ in range(m)] for _ in range(n)]

# L R U D
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(grid, start_x, start_y):
  queue = deque([(start_x, start_y)])
  visited[start_x][start_y] = 0

  min_food_dist = float('inf')

  while queue:
    x, y = queue.popleft()
    
    if grid[x][y] in [3, 4, 5]:
      min_food_dist = min(min_food_dist, visited[x][y])
    
    for i in range(4):
      nx, ny = x + dx[i], y + dy[i]
      
      if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] != 1 and visited[nx][ny] == -1:
        visited[nx][ny] = visited[x][y] + 1
        queue.append((nx, ny))

  return min_food_dist if min_food_dist != float('inf') else -1

start_x, start_y = -1, -1
for i in range(n):
  for j in range(m):
    if grid[i][j] == 2:
      start_x, start_y = i, j

result = bfs(grid, start_x, start_y)

if result == -1:
  print("NIE")
else:
  print("TAK")
  print(result)