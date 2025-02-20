import sys
input = sys.stdin.readline

r, c = map(int, input().split())
table = [input() for _ in range(r)]
strings = []

for j in range(c):
  s = ''
  for i in range(r):
    s += table[i][j]
  strings.append(s)

for i in range(1, r):
  v = set()
  for s in strings:
    v.add(s[i:])
  if len(v) != c:
    print(i - 1)
    break

else:
  print(r - 1)