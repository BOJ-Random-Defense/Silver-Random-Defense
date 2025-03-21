import sys
input = sys.stdin.readline
tasks = []

n = int(input())
for i in range(n):
  t, s = map(int, input().split())
  tasks.append([t, s])

tasks.sort(key=lambda x: x[1], reverse = True)

time = tasks[0][1]

for i in range(1, n):
  if time < tasks[i][1]:
    time -= tasks[i][0]
  else:
    time = tasks[i][1] - tasks[i][0]

if time < 0:
  print(-1)
else:
  print(time)
