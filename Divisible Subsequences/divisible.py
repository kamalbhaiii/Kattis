# Problem name: Divisible Subsequences
# Solved by: Kamal

def count_subsequences(arr, d):
  n = len(arr)
  remainder_count = {0: 1}
  current_sum = 0
  count = 0

  for i in range(n):
    current_sum = (current_sum + arr[i]) % d
    if current_sum in remainder_count:
      count += remainder_count[current_sum]
    remainder_count[current_sum] = remainder_count.get(current_sum, 0) + 1

  return count

test_cases = int(input())
for _ in range(test_cases):
  d, n = map(int, input().split())
  arr = list(map(int, input().split()))
  count = count_subsequences(arr, d)
  print(count)
