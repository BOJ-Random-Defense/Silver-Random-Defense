import sys
input = sys.stdin.readline

n = int(input())
robots = []

for i in range(n):
  x, y, v = (map(int, input().split()))
  d = (x ** 2 + y ** 2) ** 0.5
  robots.append((d / v, i + 1))

robots.sort()
for time, robot_num in robots:
  print(robot_num)