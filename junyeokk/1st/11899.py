import sys
input = sys.stdin.readline

n = input().strip();
stack = []

for char in n:
  if char == ')':
    if stack and stack[-1] == '(':
      stack.pop()
    else:
      stack.append(char)
  else:
    stack.append(char)

print(len(stack))