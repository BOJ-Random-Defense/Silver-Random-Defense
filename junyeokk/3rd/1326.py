from collections import deque
import sys
input = sys.stdin.readline

def bfs(start, end):
  queue = deque()
  queue.append((start, 0)) # 시작 값, jump 초기값
  visited = [False] * (n + 1)
  visited[start] = True

  while queue:
    pos, jump = queue.popleft()
    
    if pos == end: # 도착점에 도달했다면 점프횟수 반환
      return jump
    
    cur_num = numbers[pos]

    k = 1
    while pos + (cur_num * k) <= n:
      next_pos = pos + (cur_num * k)
      if not visited[next_pos]:
        visited[next_pos] = True
        queue.append((next_pos, jump + 1))
      k += 1
    
    k = 1
    while pos - (cur_num * k) > 0:
      next_pos = pos - (cur_num * k)
      if not visited[next_pos]:
        visited[next_pos] = True
        queue.append((next_pos, jump + 1))
      k += 1
    
  return -1

n = int(input())
numbers = [0] + list(map(int, input().split()))
start, end = map(int, input().split())

print(bfs(start, end))