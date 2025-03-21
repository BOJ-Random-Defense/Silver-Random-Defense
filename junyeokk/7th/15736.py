# n명 -> n개의 깃발. 청색 위, 백색 아래
# i번째 선수는 n개의 깃발 중 i의 배수에 해당하는 번호의 깃발을 뒤집음

import sys
input = sys.stdin.readline

n = int(input())
print(int(n ** 0.5))