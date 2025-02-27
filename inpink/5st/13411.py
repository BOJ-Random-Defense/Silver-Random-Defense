import sys
input = sys.stdin.readline

import heapq

n = int(input())
heap = []

for i in range(n):
  x, y, v = map(int, input().split())

  leng = (abs(x)**2 + abs(y)**2)**0.5
  time = leng/v
  heapq.heappush(heap, (time, i+1))

for i in range(n):
  print(heapq.heappop(heap)[1])


'''
거리=속도x시간
시간 = 거리/속도


'''