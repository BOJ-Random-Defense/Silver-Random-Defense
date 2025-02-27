import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s= list(map(int, input().split()))

from itertools import combinations

dp = [10000+1 for _ in range(10001)]
for i in range(1,2+1):
  combin = list(combinations(s, i))
  for comb in combin:
    sumComb = sum(comb)
    if sumComb==0 or sumComb>10000:
      continue

    dp[sumComb]=1

# print(dp[:100])


for i in range(1, n+1):
  for j in range(1, i):
    dp[i] = min(dp[i], dp[j]+dp[i-j])

# print(dp[:100])
if dp[n]==10001:
  print(-1)
else:
  print(dp[n])

'''
n짜장면수(1만)
m웍 개수(100)
s웍크기(n)

최대 1만그릇

1 3 (100개, 각각은 1만)

** 같은 크기의 웍을 여러 개 가지고 있을 수 있다.
100개 중에 n개 뽑는건 시간초과

1 1
2 dp[1] + dp[1]
3 1
4 1
5 2
6 2
7 
8 

'''