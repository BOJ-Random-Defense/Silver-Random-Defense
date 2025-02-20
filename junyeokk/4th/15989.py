import sys
input = sys.stdin.readline
MAX = 10001

t = int(input())
dp = [1] * MAX

for i in range(2, MAX):
  dp[i] += dp[i - 2]

for i in range(3, MAX):
  dp[i] += dp[i - 3]

for _ in range(t):
  print(dp[int(input())])