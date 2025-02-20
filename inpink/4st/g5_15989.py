import sys
input = sys.stdin.readline


t = int(input())
dp = [1 for _ in range(10001)]
# dp[1] = 1 # 1
# dp[2] = 2 # 1+1, 2
# dp[3] = 3 # 1+1+1, 1+2, 3
#dp[4] = 4 # 1+1+1+1, 1+1+2, 2+2, 1+3  (1만 더할거면 dp[3]임. 2만 더할거면 dp[2]임. 3만 더할거면 dp[1]임)
#dp[5] = 5 # 1+1+1+1+1, 1+1+1+2, 1+2+2, 1+1+3, 2+3
#dp[6] = 7 # 1+1+1+1+1+1, 1+1+1+1+2, 1+1+2+2, 1+1+1+3, 1+2+3, 2+2+2, 3+3
#dp[7] = 8 # 1+1+1+1+1+1+1, 1+1+1+1+1+2, 1+1+1+1+2+2, 1+1+1+2+3, 1+1+2+2+2, 1+2+2+3, 1+1+3+3, 2+2+3

for i in range(2, 10001):
  dp[i] += dp[i-2]

for i in range(3, 10001):
  dp[i] += dp[i-3]

for i in range(t):
  n= int(input())
  print(dp[n])

