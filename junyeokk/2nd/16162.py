import sys
input = sys.stdin.readline

n, a, d = map(int, input().split()) # 음의 개수, 고음 첫 항, 고음 공차
arr = list(map(int, input().split()))
cnt = 0

for i in range(n):
  if arr[i] == a:
    cnt += 1
    a += d

print(cnt)