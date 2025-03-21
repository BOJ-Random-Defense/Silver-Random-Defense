# 오답
import sys
input = sys.stdin.readline

n = int(input())
distances = []
prefix = [0] * (n + 1)
max_distance = 0

for _ in range(n):
  distances.append(int(input()))

for i in range(1, n + 1):
  prefix[i] = prefix[i - 1] + distances[i - 1]

for i in range(1, n + 1):
  for j in range(i + 1, n + 1):
    clockwise = prefix[j - 1] - prefix[i - 1]
    counter_clockwise = prefix[n] - clockwise
    real_distance = min(clockwise, counter_clockwise)
    max_distance = max(real_distance, max_distance)

print(max_distance)