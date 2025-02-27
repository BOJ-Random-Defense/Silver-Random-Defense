import sys
input = sys.stdin.readline


n= int(input())
s= list(map(int, input().split()))

from itertools import combinations

n = 20

sum_set = set()
for i in range(1, n+1):
  combin = list(combinations(s, i))
  for c in combin:
    # print(c)
    sum_set.add(sum(c))

# print(sum_set)

for i in range(1, 2_000_001+1):
  if i not in sum_set:
    print(i)
    break

'''
1 2 5
1
2

1 2
1 5
2 5

1 2 5

'''