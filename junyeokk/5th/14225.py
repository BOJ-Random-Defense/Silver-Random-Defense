import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
numbers.sort()

max_sum = 0

for num in numbers:
  if num > max_sum + 1:
    break
  max_sum += num

res = max_sum + 1
print(res)
