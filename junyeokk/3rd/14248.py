import sys
input = sys.stdin.readline

def dfs(current):
  visited[current] = True

  left = current - numbers[current]
  if left >= 1 and not visited[left]:
    dfs(left)
  
  right = current + numbers [current]
  if right <= n and not visited[right]:
    dfs(right)

n = int(input()) # 돌다리 개수
numbers = [0] + list(map(int, input().split())) # 각 돌에서 점프할 수 있는 거리, 0번 인덱스는 더미
start = int(input()) # 시작 위치

visited = [False] * (n + 1) # visited 배열 초기화

dfs(start)
print(visited.count(True))